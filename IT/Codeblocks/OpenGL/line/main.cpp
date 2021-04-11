#include <GL/glut.h>

void Reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void Draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0f, 0.0f, 1.0f);
  glLineWidth(1);

  glBegin(GL_LINES);
    glVertex2f(0, 0.5f);
    glVertex2f(0, -0.5f);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) exit(0); // 27 - код клавиши Esc
    y--;
    x--;
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(500, 100);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("Demo");

  glutReshapeFunc(Reshape);
  glutDisplayFunc(Draw);
  glClearColor(0, 0, 0, 0);

  glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}
