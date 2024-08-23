#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void createTree(float x,float y,float z){
    //top
glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex3f(x, y, z);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex3f(x - 0.15f, y - 0.3f, z);
    glVertex3f(x + 0.15f, y - 0.3f, z);
    glEnd();

    //middle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.825f, 0.0f);
    glVertex3f(x, y-0.15f, z);
    glColor3f(0.0f, 0.725f, 0.0f);
    glVertex3f(x - 0.2f, y - 0.5f, z);
    glVertex3f(x + 0.2f, y - 0.5f, z);
    glEnd();

    //bottom
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.775f, 0.0f);
    glVertex3f(x, y-0.35f, z);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex3f(x - 0.25f, y - 0.7f, z);
    glVertex3f(x + 0.25f, y - 0.7f, z);
    glEnd();

    //bark
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(x-0.025f, y-0.7f, z);
    glVertex3f(x+0.025f, y-0.7f, z);
    glVertex3f(x+0.025f, y-1, z);
    glVertex3f(x-0.025f, y-1, z);
    glEnd();
}

void createWater()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.9f);
    glVertex3f(-1.0,-0.6,0.0);
    glVertex3f(1.0,-0.6,0.0);
    glVertex3f(1.0,-1.0,0.0);
    glVertex3f(-1.0,-1.0,0.0);
    glEnd();

}

void createGrass()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex3f(-1.0,-0.1,0.0);
    glVertex3f(-0.3,0.0,0.0);
    glVertex3f(0.2,-0.15,0.0);
    glVertex3f(1.0,-0.175,0.0);
    glVertex3f(1.0,-0.6,0.0);
    glVertex3f(-1.0,-0.6,0.0);
    glEnd();

}
void createScene() {

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    createWater();
    createGrass();
    createTree(-0.75,0.9,0);
    createTree(+0.75,0.7,0);
    createTree(+0.65,0.65,0);
    glutSwapBuffers();
    glFlush();
}



int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,700);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("My Village");
    printf("Press \"z\" to reset the scene");
    glutDisplayFunc(createScene);
//    glutKeyboardFunc(keyPress);
    glutMainLoop();

    return 0;
}
