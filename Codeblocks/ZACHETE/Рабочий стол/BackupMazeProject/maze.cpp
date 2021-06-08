#include "maze.h"
#include "mainwindow.h"



bool deadend(int x, int y, int** maze, int height, int width){
    int a = 0;

    if(x != 1){
        if(maze[y][x-2] == pass)
            a+=1;
        }
    else a+=1;

    if(y != 1){
        if(maze[y-2][x] == pass)
            a+=1;
        }
    else a+=1;

    if(x != width-2){
        if(maze[y][x+2] == pass)
            a+=1;
        }
    else a+=1;

    if(y != height-2){
        if(maze[y+2][x] == pass)
            a+=1;
        }
    else a+=1;

    if(a == 4)
        return 1;
    else
        return 0;
}

bool ended(int** maze, int height, int width){
    bool b = 1;

    for(int i = 1; i < (height - 1); i += 2)
        for(int j = 1; j < (width - 1); j += 2)
            if(maze[i][j] == wall)
                b = 0;
    return b;
}

void mazemake(int** maze, int height, int width){
    int x, y, c, a;
    //bool b;

    // Массив заполняется ноликами
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            maze[i][j] = wall;
        }
    }

    x = 3; y = 3; a = 0;
    while(1){
        a++;
        if(a%100 == 0) {
            if(ended(maze, height, width)) {
                break;
            }
        }
        maze[y][x] = pass;
        // Бесконечный цикл, который прерывается только тупиком
        while(1){
            c = rand()%4;
            switch(c){
                case 0:
                    if(y != 1) {
                        if(maze[y-2][x] == wall){ // Вверх
                            maze[y-1][x] = pass;
                            maze[y-2][x] = pass;
                            y-=2;
                        }
                    }
                    break;
                case 1:
                    if(y != height-2) {
                       if(maze[y+2][x] == wall){ // Вниз
                           maze[y+1][x] = pass;
                           maze[y+2][x] = pass;
                           y+=2;
                       }
                    }
                    break;
                case 2:
                    if(x != 1) {
                        if(maze[y][x-2] == wall){ // Налево
                            maze[y][x-1] = pass;
                            maze[y][x-2] = pass;
                            x-=2;
                        }
                    }
                    break;
                case 3:
                    if(x != width-2) {
                        if(maze[y][x+2] == wall){ // Направо
                            maze[y][x+1] = pass;
                            maze[y][x+2] = pass;
                            x+=2;
                        }
                    }
                    break;
            }
            if(deadend(x,y,maze,height,width))
               break;
        }

        if(deadend(x,y,maze,height,width))
            do {
                x = 2*(rand()%((width-1)/2))+1;
                y = 2*(rand()%((height-1)/2))+1;
            }
            while(maze[y][x] != pass);
    }
    maze[height - 2][width - 1] = pass;
}
