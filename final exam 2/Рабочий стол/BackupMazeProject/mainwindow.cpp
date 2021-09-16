#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maze.h"
#include <QPainter>
#include <QTime>
#include <QString>
#include <math.h>
#include <QDesktopWidget>

#define PERCENT_OF_SCREEN (100)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    block_size = QApplication::desktop()->width() / 80;
    // PLACE FOR MAZE
    paintWidget = new PaintWidget(this);
    //setup size, position and other attributes using layout
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(paintWidget->sizePolicy().hasHeightForWidth());
    paintWidget->setSizePolicy(sizePolicy);
    ui->gridLayout_3->addWidget(paintWidget, 0, 0, 8, 1);
    connect(paintWidget, SIGNAL(paint_resized(QSize, QSize)), this, SLOT(paint_resized()));


    // LABELES
    level = new QLabel(tr("Level"));
    ui->gridLayout_3->addWidget(level, 0, 1, Qt::AlignTop);

    levelLcd = new QLCDNumber(2);
    ui->gridLayout_3->addWidget(levelLcd, 0, 1, Qt::AlignVCenter);
    levelLcd->setMinimumSize(block_size, block_size);

    score = new QLabel(tr("Score"));
    ui->gridLayout_3->addWidget(score, 2, 1, Qt::AlignTop);

    scoreLcd = new QLCDNumber(4);
    ui->gridLayout_3->addWidget(scoreLcd, 2, 1, Qt::AlignVCenter);
    scoreLcd->setMinimumSize(block_size, block_size);

    timer_val = new QLabel(tr("00:00"));
    ui->gridLayout_3->addWidget(timer_val, 2, 1, Qt::AlignBottom);



    // BUTTONS
    NewMaze = new QPushButton("New Level");
    NewMaze->setFocusPolicy(Qt::NoFocus);
    ui->gridLayout_3->addWidget(NewMaze, 4, 1, Qt::AlignTop);
    connect(NewMaze, SIGNAL(clicked()), this, SLOT(button_clicked()));

    ShowPath = new QPushButton("Show Path");
    ShowPath->setFocusPolicy(Qt::NoFocus);
    ui->gridLayout_3->addWidget(ShowPath, 4, 1, Qt::AlignVCenter);
    connect(ShowPath, SIGNAL(clicked()), this, SLOT(draw_path()));

    Help     = new QPushButton("Help");
    Help->setFocusPolicy(Qt::NoFocus);
    ui->gridLayout_3->addWidget(Help, 4, 1, Qt::AlignBottom);
    connect(Help, SIGNAL(clicked()), this, SLOT(help()));

    Hide     = new QPushButton("Hide Path");
    Hide->setFocusPolicy(Qt::NoFocus);
    ui->gridLayout_3->addWidget(Hide, 5, 1, Qt::AlignCenter);
    connect(Hide, SIGNAL(clicked()), this, SLOT(hide_path()));

    Exit     = new QPushButton("Exit");
    Exit->setFocusPolicy(Qt::NoFocus);
    ui->gridLayout_3->addWidget(Exit, 7, 1, Qt::AlignBottom);
    connect(Exit, &QPushButton::clicked, this, &QCoreApplication::quit);



    // TIMERS
    timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timer_overflow()));
    timer->start(120000);

    timer_show = new QTimer;
    QObject::connect(timer_show, SIGNAL(timeout()), this, SLOT(timer_show_overflow()));
    timer_show->start(500);




    // MAZE
    height = 31, width = 31;
    maze = new int*[height];
    for(int i = 0; i < height; i++) {
        maze[i] = new int[width];
    }
    point.x = block_size;
    point.y = block_size;
    saved_x = block_size;
    saved_y = block_size;



    // OTHER VARIABLES    &&    START
    started = false;
    can_draw = false;
    found_end = false;
    scale = 10;
    x0 = y0 = 0;
    setWindowTitle(tr("O"));
    resize(block_size*35, block_size*32.5);
    level_count = 1;
    sum_score = 0;
    button_clicked();
}


MainWindow::~MainWindow() {
    delete ui;
    delete paintWidget;

    delete level;
    delete levelLcd;
    delete score;
    delete scoreLcd;

    delete NewMaze;
    delete ShowPath;
    delete Help;
    delete Exit;
    delete Hide;

    delete timer_val;
    delete timer_show;
    delete timer;

    for(int i = 0; i < height; i++) {
        delete [] maze;
    }
    delete [] maze;
}

void MainWindow::check_walls() {
    // check walls
    int i = point.y / block_size, j = point.x / block_size;

    left_wall  =     (j == 0)      ? wall : maze[ i ][j-1];
    up_wall    =     (i == 0)      ? wall : maze[i-1][ j ];
    right_wall = (j == width - 1)  ? wall : maze[ i ][j+1];
    down_wall  = (i == height - 1) ? wall : maze[i+1][ j ];

}

void MainWindow::draw_o() {
    // draw circle
    QPainter painter(paintWidget->image);
    painter.fillRect(saved_x, saved_y, block_size, block_size, Qt::white);
    painter.fillRect(point.x, point.y, block_size, block_size, Qt::white);
    QPen pen;
    pen.setWidth(6);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawEllipse(point.x + block_size / 4, point.y + block_size / 4, block_size / 2 , block_size / 2);
}

void MainWindow::draw_rec(int x, int y) {
    QPainter painter(paintWidget->image);
    painter.fillRect(x, y, block_size, block_size, Qt::black);
}

void MainWindow::draw_cln() {
    QPainter painter(paintWidget->image);
    painter.fillRect(0, 0, paintWidget->width(), paintWidget->height(), Qt::white);
}

//called when button is clicked and form and widget is resized, including creation of form
void MainWindow::draw_picture() {
    draw_o();
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {
            if (!maze[i][j]){
                draw_rec(j*block_size, i*block_size);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    saved_x = point.x, saved_y = point.y;
    switch (event->key()) {
    case Qt::Key_Left:
        if (left_wall == pass) {
            point.x -= block_size;
        }
        break;
    case Qt::Key_Right:
        if (right_wall == pass) {
            point.x += block_size;
        }
        break;
    case Qt::Key_Down:
        if (down_wall == pass) {
            point.y += block_size;
        }
        break;
    case Qt::Key_Up:
        if (up_wall == pass) {
            point.y -= block_size;
        }
        break;
    }
    check_walls();
    draw_o();
    repaint();
    if ((point.x / block_size == 30) && (point.y /block_size == 29)) {
        level_count++;
        findpath(1, 1, "");       // way to count
        sum_score += path.size(); // score
        button_clicked();
    }
}

//called when button is clicked
void MainWindow::button_clicked() {
    levelLcd->display(level_count);
    scoreLcd->display(sum_score);
    started = true;
    new_path = true;
    for(int i = 0; i < height; i++) {
        delete[] maze[i];
    }
    delete[] maze;

    // initialize
    point.x = block_size;
    point.y = block_size;
    draw_cln(); // clean
    srand((unsigned)time(NULL));
    height = 31, width = 31;
    maze = new int*[height];
    for(int i = 0; i < height; i++) {
        maze[i] = new int[width];
    }

    // create && draw maze && check walls
    mazemake(maze, height, width);
    check_walls();
    draw_picture();
    repaint();
}

void MainWindow::paint_resized() {
    if (started){
        draw_picture();
        repaint();
    }
}

void MainWindow::draw_path() {
    if (started) {
        hide_path();
        QPen pen;
        QPainter painter(paintWidget->image);
        findpath(point.y / block_size, point.x / block_size, "");
        pen.setColor(Qt::red);
        pen.setWidth(4);
        painter.setPen(pen);
        for (int i = 1; i < path.size(); ++i) {
            painter.drawLine(path[i].y * block_size + block_size / 2,
                             path[i].x * block_size + block_size / 2,
                             path[i-1].y * block_size + block_size / 2,
                             path[i-1].x * block_size + block_size / 2);
        }

        new_path = false;
        sum_score -= 70;
        scoreLcd->display(sum_score);
        repaint();
    }
}

void MainWindow::hide_path() {
    if (started) {
        QPen pen;
        QPainter painter(paintWidget->image);

        if (path.size() > 0 && !new_path) {
            pen.setColor(Qt::white);
            pen.setWidth(4);
            painter.setPen(pen);
            for (int i = 1; i < path.size(); ++i) {
                painter.drawLine(path[i].y * block_size + block_size / 2,
                                 path[i].x * block_size + block_size / 2,
                                 path[i-1].y * block_size + block_size / 2,
                                 path[i-1].x * block_size + block_size / 2);
            }
        }
        path.clear();
        found_end = false;
        repaint();
    }
}

void MainWindow::help() {
    if (started) {
        QPen pen;
        QPainter painter(paintWidget->image);

        if (path.size() > 0 && !new_path) {
            pen.setColor(Qt::white);
            pen.setWidth(4);
            painter.setPen(pen);
            painter.drawLine(path[path.size() - 1].y * block_size + block_size / 2,
                             path[path.size() - 1].x * block_size + block_size / 2,
                             path[path.size() - 2].y * block_size + block_size / 2,
                             path[path.size() - 2].x * block_size + block_size / 2);
        }
        path.clear();
        found_end = false;

        findpath(point.y / block_size, point.x / block_size, "");

        pen.setColor(Qt::red);
        pen.setWidth(4);
        painter.setPen(pen);

        painter.drawLine(path[path.size() - 1].y * block_size + block_size / 2,
                         path[path.size() - 1].x * block_size + block_size / 2,
                         path[path.size() - 2].y * block_size + block_size / 2,
                         path[path.size() - 2].x * block_size + block_size / 2);
        new_path = false;
        repaint();

        sum_score -= 5;
        scoreLcd->display(sum_score);
    }
}

void MainWindow::timer_overflow() {
    sum_score = 0;
    level_count = 1;
    button_clicked();
}

void MainWindow::timer_show_overflow() {
    timer_val->setText(QTime::fromMSecsSinceStartOfDay(timer->remainingTime()).toString("hh:mm:ss"));
}

bool MainWindow::findpath(int i, int j, QString comeFrom) {
    if ((i == height-2) && (j == width-2)) {
        found_end = true;
        path.push_back({i, j});
        return true;
    }


    bool left  =     (j == 0)      ? wall : maze[ i ][j-1];
    if (left && comeFrom != "left" && found_end == false && findpath(i, j-1, "right")) {
        path.push_back({i, j});
        return true;
    }

    bool up    =     (i == 0)      ? wall : maze[i-1][ j ];
    if (up && comeFrom != "up" && found_end == false && findpath(i-1, j, "down")) {
        path.push_back({i, j});
        return true;
    }

    bool right = (j == width - 1)  ? wall : maze[ i ][j+1];
    if (right && comeFrom != "right" && found_end == false && findpath(i, j+1, "left")) {
        path.push_back({i, j});
        return true;
    }

    bool down  = (i == height - 1) ? wall : maze[i+1][ j ];
    if (down && comeFrom != "down" && found_end == false && findpath(i+1, j, "up")) {
        path.push_back({i, j});
        return true;
    }
    return false;
}
