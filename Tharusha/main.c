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

//circle
void drawCircle(float x, float y, float z, float r, float R, float G, float B) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(R, G, B);
    glutSolidSphere(r, 50, 100);
    glPopMatrix();
}

//createHorse
void horse(float x, float y, float z) {
    glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(Q, 0.0f, 1.0f, 0.0f);
        glTranslatef(-x, -y, 0.0f);
        //head
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.5f, 0.0);
        glVertex3f(x-0.1, y+0.1, z);//1
        glVertex3f(x-0.125, y+0.125, z);//2
        glVertex3f(x-0.175, y+0.125, z);//3
        glVertex3f(x-0.175, y+0.15, z);//4
        glVertex3f(x-0.15, y+0.15, z);//5
        glVertex3f(x-0.125, y+0.175, z);//6
        glVertex3f(x-0.05, y+0.1, z);//7
        glEnd();
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x-0.15, y+0.15, z);
        glVertex3f(x-0.15, y+0.125, z);
        glEnd();
        //hair
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.125, y+0.175, z);
        glVertex3f(x, y+0.1, z);
        glVertex3f(x-0.05, y+0.1, z);
        glEnd();

        //frontLeg
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.1, y, z);
        glVertex3f(x-0.075, y, z);
        glVertex3f(x-0.075, y-0.1, z);
        glVertex3f(x-0.1, y-0.1, z);
        glEnd();
        //backLeg
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.1, y, z);
        glVertex3f(x+0.075, y, z);
        glVertex3f(x+0.075, y-0.1, z);
        glVertex3f(x+0.1, y-0.1, z);
        glEnd();

        //body
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.0);
        glVertex3f(x-0.1, y, z);
        glVertex3f(x-0.1, y+0.1, z);
        glVertex3f(x+0.1, y+0.1, z);
        glVertex3f(x+0.1, y, z);
        glEnd();

        //tail
        glPushMatrix();
        glTranslatef(x+0.1, y+0.1, 0.0f);
        glRotatef(R, 0.0f, 0.0f, 1.0f);
        glTranslatef(-(x+0.1), -(y+0.1), 0.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.1, y+0.1, z);
        glVertex3f(x+0.15, y+0.1, z);
        glVertex3f(x+0.125, y, z);
        glEnd();
        glPopMatrix();
    glPopMatrix();

}

//flowerVase
void flowerVase(float x, float y, float z, float s) {
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
    drawCircle(x, y+0.225f, 1.0f, 0.03, 1.0, 0.8, 0.816);
    //rightFlower
    drawCircle(x+0.045, y+0.17f, 1.0f, 0.03, 0.5, 0.0, 1.0);
    //leftFlower
    drawCircle(x-0.045, y+0.14f, 1.0f, 0.03, 1.0, 0.0, 0.0);
    glPopMatrix();
}

//createHouse
void house(float x, float y, float z, float R, float G, float B) {
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
    glVertex3f(x+0.175f, y, z);
    glVertex3f(x-0.175f, y, z);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(x-0.055f, y+0.3f, z);
    glVertex3f(x+0.055f, y+0.3f, z);
    glVertex3f(x+0.055f, y, z);
    glVertex3f(x-0.055f, y, z);
    glEnd();
}

//createGreenary
void greenary() {
    //greenary
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex3f(-1.0, -0.2, 0.0);
    glVertex3f(-0.7, 0.1, 0.0);
    glVertex3f(-0.5, 0.2, 0.0);
    glVertex3f(0.7, 0.0, 0.0);
    glVertex3f(1.0, -0.2, 0.0);
    glVertex3f(1.0, -0.6, 0.0);
    glVertex3f(-1.0, -0.6, 0.0);
    glEnd();
}

//createWater
void water() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.8f);
    glVertex3f(-1.0, -0.6, 0.0);
    glVertex3f(1.0, -0.6, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glEnd();
}

//createTree
void tree(float x, float y, float z){
    //topLeaves
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex3f(x-0.125f, y+0.6f, z);
    glVertex3f(x, y+0.8f, z);
    glVertex3f(x+0.125f, y+0.6f, z);
    glEnd();

    //middleLeaves
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex3f(x-0.15f, y+0.5f, z);
    glVertex3f(x, y+0.7f, z);
    glVertex3f(x+0.15f, y+0.5f, z);
    glEnd();

    //lowerLeaves
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex3f(x-0.175f, y+0.4f, z);
    glVertex3f(x, y+0.6f, z);
    glVertex3f(x+0.175f, y+0.4f, z);
    glEnd();

    //trunk
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(x-0.025f, y+0.4f, z);
    glVertex3f(x+0.025f, y+0.4f, z);
    glVertex3f(x+0.025f, y, z);
    glVertex3f(x-0.025f, y, z);
    glEnd();

}

//boatAndMan
void boatAndMan(float x, float y, float z){
    //boat
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.5f, 0.0f);
    glVertex3f(x+0.35f, y+0.25f, z);
    glVertex3f(x-0.35f, y+0.25f, z);
    glVertex3f(x-0.25f, y, z);
    glVertex3f(x+0.25f, y, z);
    glEnd();
    //man
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x-0.3f, y+0.25f, z);
    glVertex3f(x-0.3f, y+0.45f, z);
    glVertex3f(x-0.2f, y+0.45f, z);
    glVertex3f(x-0.275f, y+0.35f, z);
    glVertex3f(x-0.2f, y+0.35f, z);
    glVertex3f(x-0.1f, y+0.25f, z);
    glEnd();
    //manhead
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.6f, 1.0f);
    glVertex3f(x-0.28, y+0.45, z);
    glVertex3f(x-0.28, y+0.58, z);
    glVertex3f(x-0.24, y+0.58, z);
    glVertex3f(x-0.22, y+0.5, z);
    glVertex3f(x-0.24, y+0.5, z);
    glVertex3f(x-0.24, y+0.45, z);
    glEnd();
    //hair
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-0.28, y+0.58, z);
    glVertex3f(x-0.28, y+0.6, z);
    glVertex3f(x-0.22, y+0.65, z);
    glVertex3f(x-0.24, y+0.58, z);
    glEnd();

    //paddle
    glPushMatrix();
    glTranslatef(x-0.2f, y+0.45f, 0.0f);
    glRotatef(w, 0.0f, 0.0f, 1.0f);
    glTranslatef(-(x-0.2f), -(y+0.45f), 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(x-0.2f, y+0.45f, z);
    glVertex3f(x-0.175f, y-0.1f, z);
    glVertex3f(x-0.15f, y-0.1f, z);
    glEnd();
    glPopMatrix();
}
//createYellowFish
void yFish(float x, float y ,float z){
    //body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(x-0.1f, y, z);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x+0.15f, y, z);
    glVertex3f(x, y-0.05f, z);
    glEnd();
    //fins
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x-0.0125f, y+0.1f, z);
    glVertex3f(x+0.0125f, y+0.1f, z);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x, y-0.05f, z);
    glVertex3f(x-0.0125f, y-0.1f, z);
    glVertex3f(x+0.0125f, y-0.1f, z);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x+0.15f, y, z);
    glVertex3f(x+0.2f, y+0.075f, z);
    glVertex3f(x+0.2f, y-0.075f, z);
    glEnd();
    //lines
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x, y-0.05f, z);
    glEnd();

}

//purpleFish
void pFish(float x, float y ,float z, float S){
    glPushMatrix();
    glTranslatef(x-0.1f, y, 0.0f);
    glScalef(S/2, S/2, 0.0f);
    glTranslatef(-(x-0.1f), -(y), 0.0f);
    //body
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.0f, 1.0f);
    glVertex3f(x-0.1f, y, z);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x+0.15f, y, z);
    glVertex3f(x, y-0.05f, z);
    glEnd();
    //fins
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.816f);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x-0.0125f, y+0.1f, z);
    glVertex3f(x+0.0125f, y+0.1f, z);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.816f);
    glVertex3f(x, y-0.05f, z);
    glVertex3f(x-0.0125f, y-0.1f, z);
    glVertex3f(x+0.0125f, y-0.1f, z);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.816f);
    glVertex3f(x+0.15f, y, z);
    glVertex3f(x+0.2f, y+0.075f, z);
    glVertex3f(x+0.2f, y-0.075f, z);
    glEnd();
    //lines
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.8f, 0.816f);
    glVertex3f(x, y+0.05f, z);
    glVertex3f(x, y-0.05f, z);
    glEnd();
    glPopMatrix();

}

void fruits(float x, float y ,float z) {
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(x-0.075f, y+0.4f, z);
    glVertex3f(x-0.075f, y+0.3f, z);
    glEnd();
    drawCircle(x-0.075f, y+0.3f, z, 0.025, 1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(x+0.075f, y+0.4f, z);
    glVertex3f(x+0.075f, y+0.3f, z);
    glEnd();
    drawCircle(x+0.075f, y+0.3f, z, 0.025, 1.0, 0.0, 0.0);
}

void createScene() {

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //sun
    drawCircle(0.8+F, 0.8, 0.1, 0.1, 1.0, 0.5, 0.0);

    //greenary
    greenary();
    //water
    water();

    //leftTree
    tree(-0.9, -0.3, 0.0);
    //middleTree
    tree(-0.1, 0.1, 0.0);
    fruits(-0.1, 0.1, 0.0);
    //rightTree
    tree(0.6, 0.0, 0.0);
    fruits(0.6, 0.0, 0.0);

    //rightHouse
    house(0.325, 0.0, 1.0, 1.0, 0.8, 0.816);
    //leftHouse
    house(-0.5, 0.0, 1.0, 0.5, 0.0, 1.0);

    //horse
    horse(-0.1+f+q, -0.2, 1.0);

    //no1_FlowerVase
    flowerVase(-0.7, -0.4, 1.0, S);
    //no2_FlowerVase
    flowerVase(-0.5, -0.4, 1.0, S);
    //no3_FlowerVase
    flowerVase(0.6, -0.5, 1.0, s);
    //no4_FlowerVase
    flowerVase(0.8, -0.45, 1.0, B+s);

    //yellowfish
    yFish(-0.8, -0.75, 1.0);
    glPushMatrix();
    glTranslatef(-0.5, -0.85, 0.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    glTranslatef(-(-0.5), -(-0.85), 0.0f);
    yFish(-0.5, -0.85, 1.0);
    glPopMatrix();

    //purpleFish
    pFish(0.4, -0.75, 1.0, S);
    pFish(0.7, -0.85, 1.0, S);

    //boatAndMan
    boatAndMan(-0.1+b, -0.8, 1.0);

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1100, 900);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("My Scene");
    printf("Press \"z\" to reset the scene");
    glutDisplayFunc(createScene);
    glutKeyboardFunc(keyPress);
    glutMainLoop();

    return 0;
}
