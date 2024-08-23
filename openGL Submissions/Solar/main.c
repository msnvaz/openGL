#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846


GLuint sunTexture, earthTexture, marsTexture, venusTexture;


float redAngle = 0.0f, orangeAngle = 0.0f, greenAngle = 0.0f, blueAngle = 0.0f, purpleAngle = 0.0f;

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * PI * (float)i / (float)segments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawOrbit(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * PI * (float)i / 100.0f;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Orbits
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray color for orbits
    drawOrbit(0.3f);  // Red planet orbit
    drawOrbit(0.45f);  // Orange planet orbit
    drawOrbit(0.6f);  // Green planet orbit
    drawOrbit(0.75f);  // Blue planet orbit
    drawOrbit(0.9f);  // Purple planet orbit

    // Draw Sun
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    drawCircle(0.2f, 100);

    // Draw Red Planet
    glPushMatrix();
    glRotatef(redAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.3f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    drawCircle(0.03f, 50);
    glPopMatrix();

    // Draw Orange Planet
    glPushMatrix();
    glRotatef(orangeAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.45f, 0.0f, 0.0f);
    glColor3f(1.2f, 0.7f, 0.0f);  // Orange
    drawCircle(0.04f, 50);
    glPopMatrix();

    // Draw Green Planet
    glPushMatrix();
    glRotatef(greenAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.6f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    drawCircle(0.05f, 50);
    glPopMatrix();

    // Draw Blue Planet
    glPushMatrix();
    glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.75f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    drawCircle(0.045f, 50);
    glPopMatrix();

    // Draw Purple Planet
    glPushMatrix();
    glRotatef(purpleAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.9f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.0f, 0.5f);  // Purple
    drawCircle(0.035f, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    redAngle += 0.5f;
    orangeAngle += 1.0f;
    greenAngle += 0.65f;
    blueAngle += 0.85f;
    purpleAngle += 0.7f;

    if (redAngle > 360.0f) redAngle -= 360.0f;
    if (orangeAngle > 360.0f) orangeAngle -= 360.0f;
    if (greenAngle > 360.0f) greenAngle -= 360.0f;
    if (blueAngle > 360.0f) blueAngle -= 360.0f;
    if (purpleAngle > 360.0f) purpleAngle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // 60 FPS
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solar System");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
