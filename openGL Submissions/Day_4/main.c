#include <GL/glut.h>

void createCube(void)
{
glClearColor(0,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);
glColor3f(0.0,1.0,1.0);
glVertex3f(-0.4,-0.2,0);
glVertex3f(-0.4,0.2,0);
glVertex3f(0,0.2,0);
glVertex3f(0,-0.2,0);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0,0.0,0.0);
glVertex3f(-0.4,0.2,0);
glColor3f(0,1,0);
glVertex3f(0,0.2,0);
glColor3f(0,0,1);
glVertex3f(-0.2,0.6,0);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1,0,0);
glVertex3f(-0.4,-0.2,0);
glColor3f(0,1,0);
glVertex3f(-0.4,0.2,0);
glColor3f(0,0,1);
glVertex3f(-0.8,0,0);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1,0,0);
glVertex3f(0,0.2,0);
glColor3f(0,1,0);
glVertex3f(0,-0.2,0);
glColor3f(0,0,1);
glVertex3f(0.4,0,0);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1,0,0);
glVertex3f(-0.4,-0.2,0);
glColor3f(0,1,0);
glVertex3f(0,-0.2,0);
glColor3f(0,0,1);
glVertex3f(-0.2,-0.6,0);
glEnd();

glFlush();
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("22021061");
glutDisplayFunc(createCube);

glutMainLoop();
return 0;
}
