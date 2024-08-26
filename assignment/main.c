#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat R = 0;//horse tail
GLfloat S = 1.0;//parameter for left flower vases and right fish scale
GLfloat sunm = 0.0;//Sun movement
GLfloat f = 0.0;//Horse forward
GLfloat q = 0.0;//Horse backward
GLfloat Q = 0.0;//parameter for horse direction
GLfloat w = 0.0;//paddle
GLfloat b = 0.0;//boat
GLfloat B = 1.0;//parameter for big right flower vase
GLfloat r = 1.0;//parameter for right flower vases

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
    drawSphere(0.5+sunm,0.65,0,0.15,1.0,0.5,0.0);
}

//create fish with coord,body color,fin color
void fish(float x,float y,float z,
           float R1,float G1,float B1,
           float R2,float G2,float B2,float scale){

    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(scale,scale,scale);
    glTranslatef(-x,-y,-z);

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

    glPopMatrix();
  }


void purplefish(float x,float y,float z){
    fish(x,y,z,0.5f, 0.0f, 1.0f,1.0f, 0.75f, 0.8f,1);
}

void yellowfish(float x,float y,float z){
    fish(x,y,z,1.0f, 1.0f, 0.0f,1.0f, 1.0f, 1.0f,(S/2)+0.5);
}

void flower(float x,float y,float z){
    glPushMatrix();
    drawSphere(x+0.02, y, 1.0f, 0.015, 0.5, 0.0, 1.0);
    drawSphere(x, y-0.02, 1.0f, 0.015, 1.0, 0.0, 0.0);
    drawSphere(x-0.02, y, 1.0f, 0.015, 0.5, 0.0, 1.0);
    drawSphere(x, y+0.02, 1.0f, 0.015, 1.0, 0.0, 0.0);

    drawSphere(x, y, 1, 0.015, 1.0, 0.8, 0.816);
    glPopMatrix();
}

void Vase(float x, float y, float z, float scale) {
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(scale,scale,scale);
    glTranslatef(-x,-y,-z);

    //middleStem
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(x, y);
    glVertex2f(x, y+0.225f);
    glEnd();

    //rStem
    glBegin(GL_LINES);
    glVertex2f(x, y+0.14f);
    glVertex2f(x+0.045, y+0.17f);
    glEnd();

    //lStem
    glBegin(GL_LINES);
    glVertex2f(x, y+0.1f);
    glVertex2f(x-0.045, y+0.14f);
    glEnd();

    //vase
    glBegin(GL_QUADS);
    glColor3f(0.71f, 0.40f, 0.11f);
    glVertex3f(x-0.03f, y+0.06f, z);
    glVertex3f(x+0.03f, y+0.06f, z);
    glVertex3f(x+0.02f, y, z);
    glVertex3f(x-0.02f, y, z);
    glEnd();

    //middleFlower
    flower(x, y+0.225f, z);

    //rightFlower
    flower(x+0.045, y+0.17f, z);

    //leftFlower
    flower(x-0.045, y+0.14f, z);

    glPopMatrix();
}


void Vase1(float x, float y, float z){
    Vase(x,y,z,S);
}

void Vase2(float x, float y, float z){
    Vase(x,y,z,r);
}

void BoatAndMan(float x,float y,float z){
    //boat
    glBegin(GL_QUADS);
    glColor3f(0.71f, 0.40f, 0.11f);
    glVertex3f(x, y, z);
    glVertex3f(x+0.5f, y, z);
    glVertex3f(x+0.4, y-0.2f, z);
    glVertex3f(x+0.1f, y-0.2f, z);
    glEnd();

    //man
    //body
    glBegin(GL_QUADS);
    glColor3f(0.96f, 0.96f, 0.86f);
    glVertex3f(x+0.1, y, z);
    glVertex3f(x+0.1f, y+0.2, z);
    glVertex3f(x+0.2, y+0.2f, z);
    glVertex3f(x+0.2f, y, z);
    glEnd();

    //hand
    glBegin(GL_QUADS);
    glColor3f(0.96f, 0.96f, 0.86f);
    glVertex3f(x+0.2, y+0.2, z);
    glVertex3f(x+0.3f, y+0.1, z);//fix paddle
    glVertex3f(x+0.3, y+0.08f, z);
    glVertex3f(x+0.2f, y+0.15, z);
    glEnd();

    //head
    glBegin(GL_QUADS);
    glColor3f(0.96f, 0.96f, 0.86f);
    glVertex3f(x+0.125, y+0.22, z);
    glVertex3f(x+0.175f, y+0.22, z);
    glVertex3f(x+0.175, y+0.3f, z);
    glVertex3f(x+0.125f, y+0.3, z);
    glEnd();

    //neck
    glBegin(GL_QUADS);
    glColor3f(0.96f, 0.96f, 0.86f);
    glVertex3f(x+0.135, y+0.22, z);
    glVertex3f(x+0.165f, y+0.22, z);
    glVertex3f(x+0.165, y+0.2f, z);
    glVertex3f(x+0.135f, y+0.2, z);
    glEnd();

    //hair
    glBegin(GL_QUADS);
    glColor3f(0.0, 0, 0.0);
    glVertex3f(x+0.135, y+0.32, z);
    glVertex3f(x+0.185f, y+0.33, z);
    glVertex3f(x+0.175, y+0.3f, z);
    glVertex3f(x+0.125f, y+0.3, z);
    glEnd();

    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.96f, 0.96f, 0.86f);
    glVertex3f(x+0.175, y+0.28f, z);
    glVertex3f(x+0.175f, y+0.24, z);
    glVertex3f(x+0.185f, y+0.24, z);
    glEnd();

    //paddle
    glPushMatrix();
    glTranslatef(x+0.3f, y+0.1, z);
    glRotatef(w, 0.0f, 0.0f, 1.0f);
    glTranslatef(-(x+0.3f), -(y+0.1f), 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0, 0.0);
    glVertex3f(x+0.3f, y+0.1, z);//fix paddle
    glVertex3f(x+0.5, y-0.35f, z);
    glVertex3f(x+0.45f, y-0.4, z);
    glEnd();
    glPopMatrix();
}

//horse
void horse(float x,float y,float z){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(Q, 0.0f, 1.0f, 0.0f);
    glTranslatef(-x, -y, 0.0f);

    //body
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(x, y, z);
    glVertex3f(x+0.3f, y, z);
    glVertex3f(x+0.3, y-0.15, z);
    glVertex3f(x, y-0.15, z);
    glEnd();

    //legs
    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.83f, 0.83f);
    glVertex3f(x, y-0.15, z);
    glVertex3f(x, y-0.3, z);
    glVertex3f(x+0.03, y-0.3, z);
    glVertex3f(x+0.03, y-0.15, z);
    glEnd();

    //legs
    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.83f, 0.83f);
    glVertex3f(x+0.3, y-0.15, z);
    glVertex3f(x+0.3, y-0.3, z);
    glVertex3f(x+0.27, y-0.3, z);
    glVertex3f(x+0.27, y-0.15, z);
    glEnd();

    //neck
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(x, y, z);
    glVertex3f(x+0.06f, y, z);
    glVertex3f(x, y+0.13, z);
    glVertex3f(x-0.06, y+0.1, z);
    glEnd();

    //head
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(x, y+0.13, z);
    glVertex3f(x, y+0.02, z);
    glVertex3f(x-0.12, y+0.02, z);
    glVertex3f(x-0.12, y+0.1, z);
    glEnd();

    //hair
    glBegin(GL_TRIANGLES);
    glColor3f(0.83f, 0.83f, 0.83f);
    glVertex3f(x, y+0.13, z);
    glVertex3f(x+0.1, y, z);
    glVertex3f(x+0.06, y, z);
    glEnd();

    //eye
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x-0.03, y+0.08, z);
    glEnd();

    //tail
    glPushMatrix();
    glTranslatef(x+0.3, y, z);
    glRotatef(R, 0.0f, 0.0f, 1.0f);
    glTranslatef(-(x+0.3), -(y), 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(x+0.3, y, z);
    glVertex3f(x+0.35, y, z);
    glVertex3f(x+0.35, y-0.2, z);
    glEnd();
    glPopMatrix();
glPopMatrix();
}

//keyBoardFunctions
void keyPress(unsigned char key, int x, int y){
    switch (key){
         case 'f':
            Q = 0.0f;
            f = f - 0.05;
            glutPostRedisplay();

            break;

        case 'r':
            Q = 0.0f;
            f = f - 0.015;
            R = R - 5;
            if (R<-360){
                R = 0;
            }
            glutPostRedisplay();

            break;

        case 'q':
            Q = 180.0f;
            q = q + 0.05;
            glutPostRedisplay();

            break;

        case 'b':
            b = b + 0.005;
            glutPostRedisplay();

            break;

        case 'w':
            b = b + 0.005;
            w = w - 0.5;
            if (w<-30) {
                w = 0.0;
            }
            glutPostRedisplay();

            break;

        case 'u':
            S = S + 0.05;
            glutPostRedisplay();

            break;

        case 's':
            r = r - 0.05;
            if (r < 0){
                r = 0.0;
            }
            glutPostRedisplay();

            break;

        case ' ':
            B = B - 0.05;
            if (B< 0){
                B = 1.0;
            }
            sunm = sunm - 0.05;
            if(sunm<-2.0){
                sunm = 0.0;
            }
            glutPostRedisplay();

            break;

        //Reset
        case 'z':
            R = 0;
            S = 1.0;
            sunm = 0.0;
            f = 0.0;
            q = 0.0;
            Q = 0.0;
            w = 0.0;
            b = 0.0;
            r = 1.0;
            B = 1.0;
            glutPostRedisplay();

            break;
    }
}

void Village() {

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

    //vases at left
    Vase(-0.9,-0.5,1.0,S);
    Vase(-0.7,-0.5,1.0,S);

    //vases at right
    glPushMatrix();
    glTranslatef(0.9,-0.5,1.0);
    glScalef(1,1,0);
    glTranslatef(-0.9,0.5,1.0);
    Vase(0.9,-0.5,1.0,B+r);
    glPopMatrix();
    Vase(0.7,-0.5,1.0,r);

    horse(0.2+f+q,-0.25,0);

    BoatAndMan(-0.5+b,-0.5,0.0);

    glutSwapBuffers();
    glFlush();
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("My Village");

    printf("Press \"f\" to move the horse");
    printf("Press \"r\" to rotate the tail");
    printf("Press \"q\" to rotate the horse");
    printf("Press \"b\" to move the boat");
    printf("Press \"w\" to move the bat");
    printf("Press \"u\" to scale up flower pots and fish");
    printf("Press \"s\" to scale down");
    printf("Press \" \" to move the sun");
    printf("Press \"z\" to reset the scene");
    glutDisplayFunc(Village);
    glutKeyboardFunc(keyPress);
    glutMainLoop();

    return 0;
}
