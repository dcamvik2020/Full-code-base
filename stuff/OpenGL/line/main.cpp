#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void Reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void Draw()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0f, 0.0f, 1.0f);
  glLineWidth(4);

  glBegin(GL_LINES);
    glVertex2f(0, 0.5f);
    glVertex2f(0, -0.5f);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void Draw_1()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(4);

  glBegin(GL_LINES);
    glVertex2f(0, 0.5f);
    glVertex2f(0, -0.5f);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void draw_left()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 0.0f, 0.0f);
  glLineWidth(4);

  glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, -0.0f);
  glEnd();

  glFlush();
  glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
    //if (100 < key && key < 120) 
	//if (key == GLUT_KEY_LEFT)
	if (key == 27)
	{
      //exit(0);
	  glutDisplayFunc(Draw);
	  glClearColor(0, 0, 0, 0);
      //exit(0); // 27 - код клавиши Esc
    }
	else {
	  for (int i = 0; i < 100; ++i)
        if (key == i) glutDisplayFunc(draw_left);
	  x--;
      y--;
	}
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(500, 100);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow("Demo");

  glutReshapeFunc(Reshape);
  //glutDisplayFunc(Draw);
  glutKeyboardFunc(keyboard);
  //glutDisplayFunc(draw_left);
  //glClearColor(0, 0, 0, 0);

  //glutKeyboardFunc(keyboard);

  glutMainLoop();
  return 0;
}
