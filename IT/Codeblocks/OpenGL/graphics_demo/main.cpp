#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // здесь что-то рисуется

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    // #1: Инициализация и создание окна GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 320);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Window's Title");

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    // #2: Регистрация функций-обработчиков событий
    glutDisplayFunc(display);

    // #3: Запуск основного цикла GLUT
    glutMainLoop();
}
