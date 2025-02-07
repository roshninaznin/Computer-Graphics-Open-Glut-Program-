#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846


int currentScene = 1;

float moveC1,moveC2, moveF1 = 0.0f;
bool moveRight = true;
float speed = 0.02f;

///function to display text
void renderBitmapString(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}
///function to display circle
    void drawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount) {
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void classRoom() {
    glClear(GL_COLOR_BUFFER_BIT);


     glBegin(GL_QUADS);
        glColor3f(0.95, 0.95, 0.95);
        glVertex2f(-35.0, -25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(15.0, 3.0);
        glVertex2f(35.0, -25.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.95, 0.95, 0.95);
        glVertex2f(-35.0, -25.0);
        glVertex2f(35.0, -25.0);
        glVertex2f(35.0, -35.0);
        glVertex2f(-35.0, -35.0);
    glEnd();
     glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(-35.0, -25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-35.0, 35.0);
    glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(35.0, -25.0);
        glVertex2f(15.0, 3.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(35.0, 35.0);
    glEnd();

       glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 3.0);
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-35.0, 35.0);
        glVertex2f(35.0, 35.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(-15.0, 25.0);
    glEnd();


    glLineWidth(1.00);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-35.0, 35.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(35.0, 35.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 3.0);
    glEnd();
///scenary
glLineWidth(10.00);
       glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.4);
        glVertex2f(-15.0, 13.0);
        glVertex2f(-18.0, 13.0);
        glVertex2f(15.0, 13.0);
        glVertex2f(18.0, 13.0);
        glColor3f(0.95, 0.95, 0.6);
        glVertex2f(10.80, 18.0);
        glVertex2f(10.80, 3.0);
        glEnd();

       glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(-2.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(3.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(3.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(15.0, 18.0);
        glVertex2f(11.0, 18.0);
        glVertex2f(11.0, 3.0);
        glVertex2f(15.0, 3.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(-13.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glEnd();
        glColor3f(0.6f, 0.0f, 0.0f);
        renderBitmapString(-12.70f, 14.0, GLUT_BITMAP_8_BY_13, "WORK ");
        renderBitmapString(-12.70, 11.60f, GLUT_BITMAP_8_BY_13, "HARD");


        glLineWidth(2.00);
       glBegin(GL_LINES);
        glColor3f(0.60, 0.40, 0.4);
        glVertex2f(15.0, 16.0);
        glVertex2f(11.0, 16.0);
        glVertex2f(15.0, 14.0);
        glVertex2f(11.0, 14.0);
        glVertex2f(15.0, 12.0);
        glVertex2f(11.0, 12.0);
        glVertex2f(15.0, 10.0);
        glVertex2f(11.0, 10.0);
        glVertex2f(15.0, 8.0);
        glVertex2f(11.0, 8.0);
        glVertex2f(15.0, 6.0);
        glVertex2f(11.0, 6.0);
        glVertex2f(15.0, 4.0);
        glVertex2f(11.0, 4.0);
        glVertex2f(-13.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glVertex2f(-13.50, 16.50);



        glVertex2f(-2.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glVertex2f(-2.50, 23.0);



        glVertex2f(0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glVertex2f(0.50, 23.0);
        glVertex2f(3.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(3.50, 20.0);
        glVertex2f(3.50, 20.0);
        glVertex2f(3.50, 23.0);
        glEnd();
        drawCircle(13.0,5.0,0.2,100);
        drawCircle(13.0,7.0,0.2,100);
        drawCircle(13.0,9.0,0.2,100);
        drawCircle(13.0,11.0,0.2,100);
        drawCircle(13.0,13.0,0.2,100);
        drawCircle(13.0,15.0,0.2,100);
        drawCircle(13.0,17.0,0.2,100);


///window
  glBegin(GL_QUADS);
        glColor3f(0.66, 0.80, 0.51);
        glVertex2f(-35.0, -2.50);
        glVertex2f(-18.10, 7.50);
        glVertex2f(-18.10, 22.50);
        glVertex2f(-35.0, 31.90);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-35.0, -1.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-35.0, 30.0);
        glEnd();

glPushMatrix();
    glTranslatef(moveC1, 0.0f, 0.0f);
        glColor3f(0.85, 0.9, 1.0);
    drawCircle(-33.0, 18.0, 2, 100);
    drawCircle(-32.0, 15.50, 2, 100);
    drawCircle(-31.0, 15.0, 2, 100);
    drawCircle(-34.0, 16.0, 2, 100);
    drawCircle(-30.0, 16.0, 2, 100);
    drawCircle(-23.0, 15.0, 2, 100);
    drawCircle(-22.0, 15.0, 2, 100);
    drawCircle(-23.0, 12.0, 2, 100);
    drawCircle(-25.0, 13.0, 2, 100);
    drawCircle(-20.70, 13.0, 2, 100);
glPopMatrix();




        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-35.0, -1.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-35.0, 30.0);

        glVertex2f(-27.0, 3.50);
        glVertex2f(-27.0, 26.0);
        glEnd();

        //2nd
         glBegin(GL_QUADS);
        glColor3f(0.66, 0.80, 0.51);
        glVertex2f(35.0, -2.50);
        glVertex2f(18.10, 7.50);
        glVertex2f(18.10, 22.50);
        glVertex2f(35.0, 31.90);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(35.0, -1.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(35.0, 30.0);
        glEnd();

        glPushMatrix();
    glTranslatef(moveC2, 0.0f, 0.0f);
        glColor3f(0.85, 0.9, 1.0);
    drawCircle(33.0, 18.0, 2, 100);
    drawCircle(32.0, 15.50, 2, 100);
    drawCircle(31.0, 15.0, 2, 100);
    drawCircle(34.0, 16.0, 2, 100);
    drawCircle(30.0, 16.0, 2, 100);
    drawCircle(23.0, 15.0, 2, 100);
    drawCircle(22.0, 15.0, 2, 100);
    drawCircle(23.0, 12.0, 2, 100);
    drawCircle(25.0, 13.0, 2, 100);
    drawCircle(20.70, 13.0, 2, 100);
glPopMatrix();
        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(35.0, -1.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(35.0, 30.0);

        glVertex2f(27.0, 3.50);
        glVertex2f(27.0, 26.0);

        glVertex2f(-9.0, 8.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 8.0);
        glVertex2f(9.0, 8.0);
        glVertex2f(-9.0, 8.0);
        glEnd();

        //board
        glBegin(GL_QUADS);
        glColor3f(0.4, 0.4, 0.4);
        glVertex2f(-9.0, 8.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 8.0);
        glEnd();
        //TREE
        glBegin(GL_QUADS);
        glColor3f(0.8, 0.5, 0.2);
        glVertex2f(-14.15, 3.80);
        glVertex2f(-13.50, 3.80);
        glVertex2f(-12.70, 1.0);
        glVertex2f(-14.95, 1.0);
        glEnd();
        glLineWidth(2.00);
        glBegin(GL_LINES);
        glColor3f(0.8, 0.5, 0.2);
        glVertex2f(-13.80, 3.80);
        glVertex2f(-13.80, 6.80);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.5, 0.2);
        glVertex2f(-14.90, 6.890);
        glVertex2f(-13.60, 6.850);
        glVertex2f(-13.00, 8.0);
        glEnd();


        ///desk shadow
        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(0.06, 0.80, 1.0);
        glVertex2f(-16.0, -23.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-28.0, -27.0);

        glVertex2f(-12.0, -13.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-23.0, -17.0);

        glVertex2f(-8.20, -3.45);
        glVertex2f(-10.20, -6.80);
        glVertex2f(-10.20, -6.80);
        glVertex2f(-17.70, -6.90);

        //desk
        glVertex2f(16.0, -23.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(28.0, -27.0);

        glVertex2f(12.0, -13.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(23.0, -17.0);

        glVertex2f(8.20, -3.35);
        glVertex2f(10.20, -6.90);
        glVertex2f(10.20, -6.90);
        glVertex2f(17.80, -6.90);

        //desk
        glVertex2f(8.50, -27.0);
        glVertex2f(-8.50, -27.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(-6.0, -17.0);
        glVertex2f(5.0, -6.90);
        glVertex2f(-5.0, -6.90);

         //handle
        glColor3f(0.00, 0.60, 1.0);
        glVertex2f(-16.0, -23.20);
        glVertex2f(-16.0, -27.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-18.0, -31.0);
        glVertex2f(-27.80, -27.0);
        glVertex2f(-27.80, -31.0);
        glVertex2f(-25.80, -23.0);
        glVertex2f(-25.80, -30.0);

        glVertex2f(-20.80, -13.0);
        glVertex2f(-20.80, -20.0);
        glVertex2f(-12.0, -13.0);
        glVertex2f(-12.0, -18.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-14.0, -22.0);
        glVertex2f(-23.0, -17.0);
        glVertex2f(-23.0, -22.0);

        glVertex2f(-15.60, -3.20);
        glVertex2f(-15.60, -10.20);
        glVertex2f(-8.20, -3.20);
        glVertex2f(-8.20, -8.20);
        glVertex2f(-10.20, -6.90);
        glVertex2f(-10.20, -11.90);
        glVertex2f(-17.80, -6.90);
        glVertex2f(-17.80, -11.90);

        //desk
        glVertex2f(25.80, -23.0);
        glVertex2f(25.80, -30.0);
        glVertex2f(16.0, -23.0);
        glVertex2f(16.0, -27.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(18.0, -31.0);
        glVertex2f(27.70, -27.0);
        glVertex2f(27.70, -31.0);

        glVertex2f(20.80, -13.0);
        glVertex2f(20.80, -20.0);
        glVertex2f(12.0, -13.0);
        glVertex2f(12.0, -17.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(14.0, -21.0);
        glVertex2f(22.70, -17.0);
        glVertex2f(22.70, -21.0);

        glVertex2f(15.60, -3.20);
        glVertex2f(15.60, -10.20);
        glVertex2f(8.20, -3.20);
        glVertex2f(8.20, -7.20);
        glVertex2f(10.20, -6.90);
        glVertex2f(10.20, -10.90);
        glVertex2f(17.60, -6.90);
        glVertex2f(17.60, -10.90);

        //desk
        glVertex2f(-7.0, -23.30);
        glVertex2f(-7.0, -29.0);
        glVertex2f(7.0, -23.30);
        glVertex2f(7.0, -29.0);
        glVertex2f(8.50, -27.0);
        glVertex2f(8.50, -31.0);
        glVertex2f(-8.50, -27.0);
        glVertex2f(-8.50, -31.0);

        glVertex2f(-5.0, -13.30);
        glVertex2f(-5.0, -19.0);
        glVertex2f(5.0, -13.30);
        glVertex2f(5.0, -19.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(6.0, -21.0);
        glVertex2f(-6.0, -17.0);
        glVertex2f(-6.0, -21.0);

        glVertex2f(-4.0, -3.60);
        glVertex2f(-4.0, -9.20);
        glVertex2f(4.0, -3.60);
        glVertex2f(4.0, -9.20);
        glVertex2f(5.0, -6.90);
        glVertex2f(5.0, -10.90);
        glVertex2f(-5.0, -6.90);
        glVertex2f(-5.0, -10.90);
        glEnd();

        ///desk
        glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-26.0, -23.0);
        glVertex2f(-16.0, -23.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-28.0, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-21.0, -13.0);
        glVertex2f(-12.0, -13.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-23.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-15.80, -3.20);
        glVertex2f(-8.20, -3.20);
        glVertex2f(-10.20, -6.90);
        glVertex2f(-17.80, -6.90);
        glEnd();

        //desk
         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(26.0, -23.0);
        glVertex2f(16.0, -23.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(28.0, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(21.0, -13.0);
        glVertex2f(12.0, -13.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(23.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(15.80, -3.20);
        glVertex2f(8.20, -3.20);
        glVertex2f(10.20, -6.90);
        glVertex2f(17.80, -6.90);
        glEnd();

        //desk
          glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-7.0, -23.0);
        glVertex2f(7.0, -23.0);
        glVertex2f(8.50, -27.0);
        glVertex2f(-8.50, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-5.0, -13.0);
        glVertex2f(5.0, -13.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(-6.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-4.0, -3.20);
        glVertex2f(4.0, -3.20);
        glVertex2f(5.0, -6.90);
        glVertex2f(-5.0, -6.90);
        glEnd();

        //head
        glColor3f(0.0, 0.0, 0.0);
        drawCircle(-23.0, -24.70, 0.5,100);
        drawCircle(-18.0, -14.0, 0.5,100);
        drawCircle(-13.10, -5.30, 0.5,100);
        drawCircle(23.0, -24.70, 0.5,100);
        drawCircle(18.0, -14.0, 0.5,100);
        drawCircle(13.10, -5.30, 0.5,100);
        drawCircle(-0.30, -24.80, 0.5,100);
        drawCircle(-0.30, -14.10, 0.5,100);
        drawCircle(-0.30, -5.30, 0.5,100);

         glLineWidth(25.00);
        glBegin(GL_LINES);
        glColor3f(0.9, 0.20, 0.0);
        glVertex2f(-23.0, -25.20);
        glVertex2f(-23.0, -26.50);
        glVertex2f(-18.0, -14.50);
        glVertex2f(-18.0, -17.0);
        glVertex2f(-13.10, -5.80);
        glVertex2f(-13.10, -9.30);
        glVertex2f(23.0, -25.20);
        glVertex2f(23.0, -28.70);
        glVertex2f(18.0, -14.50);
        glVertex2f(18.0, -17.0);
         glVertex2f(13.10, -5.80);
        glVertex2f(13.10, -9.30);
        glVertex2f(-0.30, -25.30);
        glVertex2f(-0.30, -27.80);
        glVertex2f(-0.30, -14.60);
        glVertex2f(-0.30, -16.10);
        glVertex2f(-0.30, -5.80);
        glVertex2f(-0.30, -8.30);
        glEnd();

        //chair
        glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-24.0, -26.0);
        glVertex2f(-22.0, -26.0);
        glVertex2f(-21.50, -30.0);
        glVertex2f(-24.50, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-19.0, -15.30);
        glVertex2f(-17.0, -15.30);
        glVertex2f(-16.50, -19.0);
        glVertex2f(-19.50, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-14.10, -6.50);
        glVertex2f(-12.30, -6.50);
        glVertex2f(-11.80, -9.50);
        glVertex2f(-14.60, -9.50);
        glEnd();

        //desk
           glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(24.0, -26.0);
        glVertex2f(22.0, -26.0);
        glVertex2f(21.50, -30.0);
        glVertex2f(24.50, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(19.0, -15.30);
        glVertex2f(17.0, -15.30);
        glVertex2f(16.50, -19.0);
        glVertex2f(19.50, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(14.10, -6.50);
        glVertex2f(12.30, -6.50);
        glVertex2f(11.80, -9.50);
        glVertex2f(14.60, -9.50);
        glEnd();

        //desk
             glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.30, -26.0);
        glVertex2f(0.70, -26.0);
        glVertex2f(1.70, -30.0);
        glVertex2f(-2.30, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.20, -15.30);
        glVertex2f(0.60, -15.30);
        glVertex2f(1.60, -19.0);
        glVertex2f(-2.20, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.10, -6.50);
        glVertex2f(0.50, -6.50);
        glVertex2f(1.40, -9.50);
        glVertex2f(-2.00, -9.50);
        glEnd();

         //chair handle
        glLineWidth(4.00);
        glBegin(GL_LINES);
        glColor3f(0.76, 0.30, 0.20);
        glVertex2f(-23.40, -30.0);
        glVertex2f(-24.0, -32.0);
        glVertex2f(-22.50, -30.0);
        glVertex2f(-22.0, -32.0);

        glVertex2f(-18.40, -19.0);
        glVertex2f(-19.10, -21.0);
        glVertex2f(-17.50, -19.0);
        glVertex2f(-16.90, -21.0);

        glVertex2f(-13.70, -9.50);
        glVertex2f(-14.40, -11.50);
        glVertex2f(-12.70, -9.50);
        glVertex2f(-12.10, -11.50);

        //
        glVertex2f(23.40, -30.0);
        glVertex2f(24.0, -32.0);
        glVertex2f(22.50, -30.0);
        glVertex2f(22.0, -32.0);

        glVertex2f(18.40, -19.0);
        glVertex2f(19.10, -21.0);
        glVertex2f(17.50, -19.0);
        glVertex2f(16.90, -21.0);

        glVertex2f(13.70, -9.50);
        glVertex2f(14.30, -11.50);
        glVertex2f(12.80, -9.50);
        glVertex2f(12.30, -11.50);

        //desk
        glVertex2f(0.30, -30.0);
        glVertex2f(0.90, -32.0);
        glVertex2f(-0.90, -30.0);
        glVertex2f(-1.40, -32.0);

        glVertex2f(0.30, -19.0);
        glVertex2f(0.80, -21.0);
        glVertex2f(-0.90, -19.0);
        glVertex2f(-1.30, -21.0);

        glVertex2f(0.20, -9.50);
        glVertex2f(0.70, -11.50);
        glVertex2f(-0.80, -9.50);
        glVertex2f(-1.30, -11.50);
        glEnd();


///Text
         glColor3f(1.0f, 1.0f, 0.4f);
        renderBitmapString(-4.50f, 16.0f, GLUT_BITMAP_HELVETICA_12, "Play , Learn And Fun- Primary to SSC");
        renderBitmapString(-3.0f, 13.0f, GLUT_BITMAP_HELVETICA_18, "Rain rain go away...");
        renderBitmapString(-5.0f, 10.0f, GLUT_BITMAP_HELVETICA_12, "Bangla, English, Math, BGS, Islam, Science");

    ///Faculty
    glPushMatrix();
    glTranslatef(moveF1, 0.0f, 0.0f);
        //madam
        glLineWidth(8.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.90);
        glVertex2f(-10.80, 9.10);
        glVertex2f(-10.0, 10.10);

        glVertex2f(-11.50, 0.0);
        glVertex2f(-12.00, 0.0);
        glVertex2f(-10.50, 0.0);
        glVertex2f(-11.00, 0.0);
        glEnd();
        glLineWidth(2.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.70);
        glVertex2f(-10.0, 10.10);
        glVertex2f(-5.0, 14.10);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.2, 0.8, 1.0);
        glVertex2f(-10.80, 11.10);
        glVertex2f(-12.0, 11.10);
        glVertex2f(-12.40, 7.0);
        glVertex2f(-10.40, 7.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.7);
        glVertex2f(-12.20, 7.0);
        glVertex2f(-11.10, 7.0);
        glVertex2f(-11.60, 0.0);
        glVertex2f(-12.00, 0.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.55, 0.7);
        glVertex2f(-12.0, 7.0);
        glVertex2f(-10.70, 7.0);
        glVertex2f(-10.60, 0.0);
        glVertex2f(-11.00, 0.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        drawCircle(-11.50, 12.50,0.70,100);
        drawCircle(-11.50, 11.50,0.40,100);
        glEnd();
    glPopMatrix();


glutSwapBuffers();
 }
void renderScene() {
    if (currentScene == 1) {
classRoom();    }
}



void updateC1(int value)
{
    if(moveC1 < -25.0)
    {
        moveC1 = 0;
    }
    moveC1 -= 0.15;

    glutTimerFunc(50, updateC1, 0);
    glutPostRedisplay();

}

void updateC2(int value)
{
    if(moveC2 > 25.0)
    {
        moveC2 = 0;
    }
    moveC2 += 0.15;

    glutTimerFunc(50, updateC2, 0);
    glutPostRedisplay();

}


// Variable to control direction

void updateF1(int value) {
    if (moveRight) {
        // Move right to left
        if (moveF1 > 14.0f) {
            moveRight = false;  // Switch direction to move left
        }
        moveF1 += 0.05f;  // Move right
    } else {
        // Move left to right
        if (moveF1 < -2.0f) {
            moveRight = true;  // Switch direction to move right
        }
        moveF1 -= 0.05f;  // Move left
    }

    glutPostRedisplay();
    glutTimerFunc(40, updateF1, 0);
}


void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-35.0, 35.0, -35.0, 35.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Classroom");

    init();
    glutTimerFunc(100, updateC1, 1);
    glutTimerFunc(100, updateC2, 1);
    glutTimerFunc(100, updateF1, 0);

    glutDisplayFunc(renderScene);

    sndPlaySound("classroom-college.wav", SND_ASYNC);
    //  sndPlaySound("kids-in-classroom.wav", SND_ASYNC);


    glutMainLoop();
    return 0;
}
