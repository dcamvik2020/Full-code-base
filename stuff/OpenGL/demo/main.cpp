#include <stdio.h>
#include <GL/glut.h>

int WindW, WindH;
int i;
int alpha;

void Reshape(int width, int height) // Reshape function
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);

  WindW = width;
  WindH = height;
}

void Draw(void) // Window redraw function
{
  glClear(GL_COLOR_BUFFER_BIT);

  glLineWidth(3);
  glColor3f(0.0f, 0.6f, 0.9f);

  glPushMatrix();
  glRotatef(alpha, 0.0f, 0.0f, 1.0f);
  alpha += 4;
  if (alpha > 359) alpha = 0;
  glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
  glEnd();
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void Visibility(int state) // Visibility function
{
  if (state == GLUT_NOT_VISIBLE) printf("Window not visible!\n");
  if (state == GLUT_VISIBLE) printf("Window visible!\n");
}

void timf(int value) // Timer function
{
  glutPostRedisplay();  // Redraw windows
  glutTimerFunc(1, timf, 0); // Setup next timer
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) exit(0); // 27 - код клавиши Esc
}

int main(int argc, char *argv[])
{
  WindW = 400;
  WindH = 300;
  alpha = 0;

  glutInit(&argc, argv);
  glutInitWindowSize(WindW, WindH);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  (void)glutCreateWindow("Romka Demo");

  glutReshapeFunc(Reshape); // Set up reshape function
  glutDisplayFunc(Draw);    // Set up redisplay function
  glutTimerFunc(1, timf, 0); // Set up timer for 40ms, about 25 fps
  glutVisibilityFunc(Visibility); // Set up visibility funtion
  glClearColor(0, 0, 0, 0);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
