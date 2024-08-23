#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat R = 0;//parameter for horse tail rotation
GLfloat S = 1.0;//parameter for left flower vases and right fish scale
GLfloat F = 0.0;//parameter for Sun movement
GLfloat f = 0.0;//parameter for horse forward movement
GLfloat q = 0.0;//parameter for horse backward movement
GLfloat Q = 0.0;//parameter for horse direction
GLfloat w = 0.0;//parameter for paddle
GLfloat b = 0.0;//parameter for boat
GLfloat B = 1.0;//parameter for big right flower vase
GLfloat s = 1.0;//parameter for right flower vases

//keyBoardFunctions
void keyPress(unsigned char key, int x, int y){
    switch (key){
        case 'r':
            R = R - 5;
            if (R<-360){
                R = 0;
            }
            glutPostRedisplay();
            break;
        case 'u':
            S = S + 0.05;
            glutPostRedisplay();
            break;
        case ' ':
            B = B - 0.05;
            if (B< 0){
                B = 1.0;
            }
            F = F - 0.05;
            if(F<-2.0){
                F = 0.0;
            }
            glutPostRedisplay();
            break;
        case 'f':
            Q = 0.0f;
            f = f - 0.05;
            glutPostRedisplay();
            break;
        case 'q':
            Q = 180.0f;
            q = q + 0.05;
            glutPostRedisplay();
            break;
        case 'w':
            w = w - 0.5;
            if (w<-20) {
                w = 0.0;
            }
            glutPostRedisplay();
            break;
        case 'b':
            b = b + 0.05;
            if (b>1) {
                b = 0.0;
            }
            glutPostRedisplay();
            break;
        case 's':
            s = s - 0.05;
            if (s < 0){
                s = 1.0;
            }
            glutPostRedisplay();
            break;
        case 'z'://Reset
            R = 0;
            S = 1.0;
            F = 0.0;
            f = 0.0;
            q = 0.0;
            Q = 0.0;
            w = 0.0;
            b = 0.0;
            s = 1.0;
            B = 1.0;
            glutPostRedisplay();
            break;
    }
}

void bg(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f,0.0f);
    glVertex3f(-1.0,1.0,0.0);
    glColor3f(1.0f, 1.0f,0.7f);
    glVertex3f(1.0,1.0,0.0);
    glColor3f(1.0f, 1.0f,0.0f);
    glVertex3f(1.0,-1.0,0.0);
    glColor3f(1.0f, 0.8f,0.0f);
    glVertex3f(-1.0,-1.0,0.0);
    glEnd();;

}
void createTree1(float x,float y,float z){
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

void drawSphere(float x, float y, float z, float r,float R,float G,float B) {
    glPushMatrix();
    glColor3f(R,G,B);
    glTranslatef(x, y, z);
    glutSolidSphere(r, 50, 50); // 50 slices and 50 stacks for a smooth sphere
    glPopMatrix();
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
    glColor3f(0.3f, 0.7f, 0.0f);
    glVertex3f(0.2,-0.15,0.0);
    glVertex3f(1.0,-0.175,0.0);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex3f(1.0,-0.6,0.0);
    glVertex3f(-1.0,-0.6,0.0);
    glEnd();

}

void createHouse(float x, float y, float z, float R, float G, float B) {
    //roof
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x-0.175f, y+0.5f, z);
    glVertex3f(x+0.175f, y+0.5f, z);
    glVertex3f(x+0.225f, y+0.4f, z);
    glVertex3f(x-0.225f, y+0.4f, z);
    glEnd();

    //house
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
    glVertex3f(x-0.175f, y+0.4f, z);
    glVertex3f(x+0.175f, y+0.4f, z);
    glVertex3f(x+0.175f, y+0.1,z);
    glVertex3f(x-0.175f, y+0.1, z);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(x-0.055f, y+0.3f, z);
    glVertex3f(x+0.055f, y+0.3f, z);
    glVertex3f(x+0.055f, y+0.1, z);
    glVertex3f(x-0.055f, y+0.1, z);
    glEnd();
}

void createTree2(float x, float y, float z){
    createTree1(x,y,z);

    //fruits
    glBegin(GL_LINES);
    glColor3f(0.4f,0.3f,0.0f);
    glVertex3f(x + 0.15f, y - 0.7f, z);
    glVertex3f(x + 0.15f, y - 0.8f, z);
    glEnd();
    drawSphere(x + 0.15f, y - 0.8f, z,0.025,1,0,0);

    glBegin(GL_LINES);
    glColor3f(0.4f,0.3f,0.0f);
    glVertex3f(x - 0.15f, y - 0.7f, z);
    glVertex3f(x - 0.15f, y - 0.8f, z);
    glEnd();
    drawSphere(x - 0.15f, y - 0.8f, z,0.025,1,0,0);
}

//sun
void sun(){
    drawSphere(0.5,0.65,0,0.15,1.0,0.5,0.0);
}

//create fish with coord,body color,fin color
void fish(float x,float y,float z,
           float R1,float G1,float B1,
           float R2,float G2,float B2){
    //body
    glBegin(GL_TRIANGLES);
    glColor3f(R1,G1,B1);
    glVertex3f(x,y,z);
    glVertex3f(x+0.05,y+0.025,z);
    glVertex3f(x+0.05,y-0.025,z);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(R1,G1,B1);
    glVertex3f(x+0.05,y+0.025,z);
    glVertex3f(x+0.05,y-0.025,z);
    glVertex3f(x+0.1,y,z);
    glEnd();

//fins

    glBegin(GL_TRIANGLES);
    glColor3f(R2,G2,B2);
    glVertex3f(x+0.1,y,z);
    glVertex3f(x+0.15,y+0.025,z);
    glVertex3f(x+0.15,y-0.025,z);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(R2,G2,B2);
    glVertex3f(x+0.05,y+0.025,z);
    glVertex3f(x+0.075,y+0.0125,z);
    glVertex3f(x+0.085,y+0.05,z);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(R2,G2,B2);
    glVertex3f(x+0.075,y-0.0125,z);
    glVertex3f(x+0.05,y-0.025,z);
    glVertex3f(x+0.085,y-0.05,z);
    glEnd();

    //lines
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x+0.05,y+0.025,z);
    glVertex3f(x+0.05,y-0.025,z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x+0.075,y-0.0125,z);
    glVertex3f(x+0.075,y+0.0125,z);
    glEnd();

    //eye
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x+0.025,y,z);
    glEnd();
  }


void purplefish(float x,float y,float z){
    fish(x,y,z,0.5f, 0.0f, 1.0f,1.0f, 0.75f, 0.8f);
}

void yellowfish(float x,float y,float z){
    fish(x,y,z,1.0f, 1.0f, 0.0f,1.0f, 1.0f, 1.0f);
}

void Vase(float x, float y, float z, float s) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(s, s, 0.0f);
    glTranslatef(-(x), -(y), 0.0f);
    //vase
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.8f, 0.9f);
    glVertex3f(x-0.025f, y+0.06f, z);
    glVertex3f(x+0.025f, y+0.06f, z);
    glVertex3f(x+0.015f, y, z);
    glVertex3f(x-0.015f, y, z);
    glEnd();

    //middleStem
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y+0.225f);
    glEnd();
    //rightStem
    glBegin(GL_LINES);
    glVertex2f(x, y+0.14f);
    glVertex2f(x+0.045, y+0.17f);
    glEnd();
    //leftStem
    glBegin(GL_LINES);
    glVertex2f(x, y+0.1f);
    glVertex2f(x-0.045, y+0.14f);
    glEnd();
    //middleFlower
    drawSphere(x, y+0.225f, 1.0f, 0.025, 1.0, 0.8, 0.816);
    //rightFlower
    drawSphere(x+0.045, y+0.17f, 1.0f, 0.025, 0.5, 0.0, 1.0);
    //leftFlower
    drawSphere(x-0.045, y+0.14f, 1.0f, 0.025, 1.0, 0.0, 0.0);
    glPopMatrix();
}

void createScene() {

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    bg();
    sun();
    createWater();
    createGrass();
    //purplehouse
    createHouse(0.4,-0.3,0.0,0.5, 0.0, 1.0);
    createTree2(-0.75,0.9,0);
    createTree1(+0.85,0.8,0);
    createTree2(+0.65,0.65,0);
    //pink house
    createHouse(-0.5,-0.3,0.0,1.0, 0.75, 0.8);
    purplefish(-0.9,-0.8,0);

    glPushMatrix();
    glTranslatef(-0.7, -0.85, 0.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    glTranslatef(-(-0.7), -(-0.85), 0.0f);
    purplefish(-0.8,-0.7,0);
    glPopMatrix();

    yellowfish(0.7,-0.8,0);
    yellowfish(0.5,-0.9,0);

    Vase(-0.7,-0.4,1.0,0);
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
