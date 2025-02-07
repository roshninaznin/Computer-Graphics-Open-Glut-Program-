#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846


int currentScene = 1;

float moveB, moveC, moveW, moveN3, moveN4= 0.0f;
float moveMM2 = 0.0f;
bool extraObjectVisible = false;
bool isVisible = false;
bool movingDown = false;

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


void universityLife() {
    glClear(GL_COLOR_BUFFER_BIT);

 /// Sky
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.75f, 1.0f);
    glVertex2f(-35.0, 35.0);
    glVertex2f(35.0, 35.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///Sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(-13.00f, 27.00f, 1.0f, 100);
    glEnd();

    ///Clouds
    ///Cloud-01
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();

    glColor3d(255,255,255);
    drawCircle(-12.00f, 18.00f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-12.00f, 19.00f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-11.00f, 19.00f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-11.00f, 18.00f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-10.00f, 18.5f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-13.00f, 18.50f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

    ///cloud-02
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3d(255,255,255);
    drawCircle(25.00f, 18.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(25.00f, 19.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(26.00f, 19.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(26.00f, 18.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(27.00f, 18.5f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(24.00f, 18.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

    ///cloud-03
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3d(255,255,255);
    drawCircle(10.00f, 23.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(10.00f, 24.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(11.00f, 24.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(11.00f, 23.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(12.00f, 23.5f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(9.00f, 23.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();

    glEnd();

    ///cloud-04
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3d(255,255,255);
    drawCircle(-25.00f, 23.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-25.00f, 24.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-26.00f, 24.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-26.00f, 23.0f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-27.00f, 23.5f, 1.0f, 100);
    glColor3d(255,255,255);
    drawCircle(-24.00f, 23.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

     /// Birds 1st
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   glLineWidth(0.5);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(-12.0f, 21.0f);
   glVertex2f(-11.95f, 20.5f);
   glVertex2f(-11.95f, 20.5f);
   glVertex2f(-11.5f, 21.0f);
   glEnd();

   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(-11.0f, 22.0f);
   glVertex2f(-10.95f, 21.5f);
   glVertex2f(-10.95f, 21.5f);
   glVertex2f(-10.55f, 22.0f);
   glEnd();

    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(-10.0f, 21.0f);
    glVertex2f(-9.95f, 20.5f);
    glVertex2f(-9.95f, 20.5f);
    glVertex2f(-9.5f, 21.0f);
    glEnd();

    glPopMatrix();

    /// Birds 2nd
  glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   glLineWidth(0.1);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(11.0f, 21.0f);
   glVertex2f(11.05f, 20.5f);
   glVertex2f(11.05f, 20.5f);
   glVertex2f(11.45f, 21.0f);

   glEnd();

   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(10.0f, 22.0f);
   glVertex2f(10.05f, 21.5f);
   glVertex2f(10.05f, 21.5f);
   glVertex2f(10.45f, 22.0f);
   glEnd();

    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(9.0f, 21.0f);
    glVertex2f(9.05f, 20.5f);
    glVertex2f(9.05f, 20.5f);
    glVertex2f(9.45f, 21.0f);
    glEnd();

    glPopMatrix();

    /// Birds 3rd
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);

   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(25.0f, 21.0f);
   glVertex2f(25.05f, 20.5f);
   glVertex2f(25.05f, 20.5f);
   glVertex2f(25.45f, 21.0f);
   glEnd();

   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(24.0f, 22.0f);
   glVertex2f(24.05f, 21.5f);
   glVertex2f(24.05f, 21.5f);
   glVertex2f(24.45f, 22.0f);
   glEnd();

    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(23.0f, 21.0f);
    glVertex2f(23.05f, 20.5f);
    glVertex2f(23.05f, 20.5f);
    glVertex2f(23.45f, 21.0f);
    glEnd();

    glPopMatrix();

      /// Birds 4TH
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   glLineWidth(0.5);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(-25.0f, 21.0f);
   glVertex2f(-24.95f, 20.5f);
   glVertex2f(-24.95f, 20.5f);
   glVertex2f(-24.5f, 21.0f);
   glEnd();

   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(-24.0f, 22.0f);
   glVertex2f(-23.95f, 21.5f);
   glVertex2f(-23.95f, 21.5f);
   glVertex2f(-23.55f, 22.0f);
   glEnd();

    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(-23.0f, 21.0f);
    glVertex2f(-22.95f, 20.5f);
    glVertex2f(-22.95f, 20.5f);
    glVertex2f(-22.5f, 21.0f);
    glEnd();

    glPopMatrix();
    ///green middle ground
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.9f, 0.4f);
    glVertex2f(-35.0, 0.0);
    glVertex2f(35.0, 0.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -20.0);
    glVertex2f(-35.0, -20.0);
    glEnd();



    ///basket ball ground
     glBegin(GL_QUADS);
    glColor3f(0.7f, 0.9f, 0.4f);
    glVertex2f(-35.0, -2.0);
    glVertex2f(35.0, -2.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -14.0);
    glVertex2f(-35.0, -14.0);
    glEnd();

     ///busket
    glColor3f(0.8f, 0.9f, 0.6f);
      drawCircle(-35.0, -8.0, 4.0, 100);
      drawCircle(-14.0, -8.0, 4.0, 100);
      drawCircle(-24.3, -8.0, 0.8, 100);

      drawCircle(35.0, -8.0, 4.0, 100);
      drawCircle(14.0, -8.0, 4.0, 100);
      drawCircle(24.3, -8.0, 0.8, 100);
        drawCircle(0.0, -8.0, 0.8, 100);

        glColor3f(0.6f, 0.9f, 0.3f);
     drawCircle(-35.0, -8.0, 3.0, 100);
      drawCircle(-14.0, -8.0, 3.0, 100);

       drawCircle(35.0, -8.0, 3.0, 100);
      drawCircle(14.0, -8.0, 3.0, 100);




    glEnd();



 //busket line
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-31.0, -8.0);
    glVertex2f(-18.0, -8.0);

    glVertex2f(-17.50, -2.0);
     glVertex2f(-19.80, -14.0);
     glVertex2f(-28.0, -2.0);
     glVertex2f(-31.0, -14.0);

    glVertex2f(-31.0, -8.0);
    glVertex2f(31.0, -8.0);

    glVertex2f(17.50, -2.0);
     glVertex2f(19.80, -14.0);
     glVertex2f(28.0, -2.0);
     glVertex2f(31.0, -14.0);

     glVertex2f(-5.0, -2.0);
     glVertex2f(-6.50, -14.0);

     glVertex2f(5.0, -2.0);
     glVertex2f(6.50, -14.0);

    glEnd();



    ///Road
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.55f, 0.55f);
    glVertex2f(-35.0, -20.0);
    glVertex2f(35.0, -20.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(35.0, -35.0);
    glVertex2f(-35.0, -35.0);
    glEnd();
    ///ROAD LINE
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    //Road
    glVertex2f(-35.0, -21.0);
    glVertex2f(35.0, -21.0);
    glEnd();



    ///yellow
    glLineWidth(4.0);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-37.0f, -30.5f);
    glVertex2f(-33.0f, -30.5f);

    glVertex2f(-30.0f, -30.5f);
    glVertex2f(-27.0f, -30.5f);

    glVertex2f(-24.0f, -30.5f);
    glVertex2f(-21.0f, -30.5f);

    glVertex2f(-18.0f, -30.5f);
    glVertex2f(-15.0f, -30.5f);

    glVertex2f(-12.0f, -30.5f);
    glVertex2f(-9.0f, -30.5f);

    glVertex2f(-6.0f, -30.5f);
    glVertex2f(-3.0f, -30.5f);

    glVertex2f(0.0f, -30.5f);
    glVertex2f(3.0f, -30.5f);

    glVertex2f(6.0f, -30.5f);
    glVertex2f(9.0f, -30.5f);

    glVertex2f(12.0f, -30.5f);
    glVertex2f(15.0f, -30.5f);

    glVertex2f(18.0f, -30.5f);
    glVertex2f(21.0f, -30.5f);


    glVertex2f(24.0f, -30.5f);
    glVertex2f(27.0f, -30.5f);

    glVertex2f(30.0f, -30.5f);
    glVertex2f(33.0f, -30.5f);

    glVertex2f(36.0f, -30.5f);
    glVertex2f(39.0f, -30.5f);

   ///arrow
     glColor3f(0.9f, 0.9f, 0.9f);
     glVertex2f(-20.00f, -24.0f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -24.5f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -23.5f);
     glVertex2f(-18.0f, -24.0f);

     glVertex2f(15.0f, -24.0f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -24.5f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -23.5f);
     glVertex2f(17.0f, -24.0f);

    glEnd();

    ///round

    glColor3f(0.6f, 0.8f, 0.9f);
    drawCircle(0.0, 27.0, 8.10, 1000);

    glColor3f(0.2f, 0.3f, 0.7);
    drawCircle(0.0, 27.0, 8.0, 1000);
    glLineWidth(2.0);

    glBegin(GL_LINES);
    glColor3f(0.6f, 0.8f, 0.9f);
    glVertex2f(-5.0, 33.5);
    glVertex2f(5.10, 33.5);
    glVertex2f(-7.10, 30.9);
    glVertex2f(7.00, 30.9);
    glVertex2f(-7.90, 28.30);
    glVertex2f(7.90, 28.30);
    glVertex2f(-7.90, 25.80);
    glVertex2f(7.90, 25.80);
    glVertex2f(-7.20, 23.20);
    glVertex2f(7.90, 23.20);
    glVertex2f(-5.0, 20.60);
    glVertex2f(5.0, 20.60);

    glVertex2f(0, 35.0);
    glVertex2f(0, 19.0);
    glVertex2f(-4, 34.0);
    glVertex2f(-2, 19.0);
    glVertex2f(-7, 31.0);
    glVertex2f(-4, 20.0);
    glVertex2f(4, 34.0);
    glVertex2f(2, 19.0);
    glVertex2f(7, 31.0);
    glVertex2f(4, 20.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-15.0, 15.0);
    glVertex2f(0.0, 19.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(-15.0, -2.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(15.0, 15.0);
    glVertex2f(0.0, 19.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(15.0, -2.0);
    glEnd();

    ///aiub building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-35.0, 23.0);
    glVertex2f(-18.0, 20.0);
    glVertex2f(-18.0, -2.0);
    glVertex2f(-35.0, -8.0);
    glEnd();


    glLineWidth(16.50);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 1.0f);
     glVertex2f(-35.0, 5.20);
    glVertex2f(-17.50, 6.70);
    glVertex2f(-17.50, 19.70);
    glVertex2f(-35.0, 20.80);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-35.0, 8.50);
    glVertex2f(-17.50, 8.50);
     glVertex2f(-35.0, 7.00);
    glVertex2f(-17.50, 7.00);
    glVertex2f(-18.50, 24.20);
    glVertex2f(-35.0, 27.90);


    glEnd();

 glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
     glVertex2f(-35.0, 18.0);
    glVertex2f(-18.80, 16.50);
    glVertex2f(-18.80, 12.50);
    glVertex2f(-35.0, 13.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-35.0, 2.0);
    glVertex2f(-18.80, 4.0);
    glVertex2f(-18.80, 0.70);
    glVertex2f(-35.0, -4.20);
    glEnd();
//text window
   glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-9.50, 15.40);
    glVertex2f(9.50, 15.40);
    glVertex2f(9.50, 13.50);
    glVertex2f(-9.50, 13.50);
    glEnd();
//upper window
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-13.0, 12.0);
    glVertex2f(13.0, 12.0);
    glVertex2f(13.0, 7.0);
    glVertex2f(-13.0, 7.0);
    glEnd();

    //door side window
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-13.0, 5.0);
    glVertex2f(-4.0, 5.0);
    glVertex2f(-4.0, 0.0);
    glVertex2f(-13.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(13.0, 5.0);
    glVertex2f(4.0, 5.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(13.0, 0.0);
    glEnd();

   //door
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-3.0, 5.0);
    glVertex2f(3.0, 5.0);
    glVertex2f(3.0, -2.0);
    glVertex2f(-3.0, -2.0);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-35.0, 10.70);
    glVertex2f(-18.0, 10.70);
     glColor3f(0.5f, 0.5f, 0.9f);

    glVertex2f(-35.0, 15.0);
    glVertex2f(-18.80, 15.0);
    glVertex2f(-35.0, -1.5);
    glVertex2f(-18.80, 2.0);

//window
     glVertex2f(-34.0, 17.80);
    glVertex2f(-34.0, 13.0);
      glVertex2f(-28.0, 17.50);
    glVertex2f(-28.0, 12.80);
      glVertex2f(-21.0, 17.0);
    glVertex2f(-21.0, 12.60);

    glVertex2f(-34.0, 2.10);
    glVertex2f(-34.0, -4.10);
    glVertex2f(-28.0, 3.0);
    glVertex2f(-28.0, -2.10);
    glVertex2f(-21.0, 4.0);
    glVertex2f(-21.0, 0.0);

    glVertex2f(-15.0, -2.0);
    glVertex2f(15.0, -2.0);

    //window line

    glVertex2f(-13.0, 9.5);
    glVertex2f(13.0, 9.5);
    glVertex2f(-10.0, 12.0);
    glVertex2f(-10.0, 7.0);
    glVertex2f(-7.0, 12.0);
    glVertex2f(-7.0, 7.0);
    glVertex2f(-4.0, 12.0);
    glVertex2f(-4.0, 7.0);
    glVertex2f(0.0, 12.0);
    glVertex2f(0.0, 7.0);
    glVertex2f(4.0, 12.0);
    glVertex2f(4.0, 7.0);
    glVertex2f(13.0, 9.5);
    glVertex2f(13.0, 9.5);
    glVertex2f(10.0, 12.0);
    glVertex2f(10.0, 7.0);
    glVertex2f(7.0, 12.0);
    glVertex2f(7.0, 7.0);

    glVertex2f(-13.0, 2.5);
    glVertex2f(-4.0, 2.5);
    glVertex2f(13.0, 2.5);
    glVertex2f(4.0, 2.5);

   glVertex2f(-10.0, 5.0);
    glVertex2f(-10.0, 0.0);
    glVertex2f(-7.0, 5.0);
    glVertex2f(-7.0, 0.0);
    glVertex2f(-4.0, 5.0);
    glVertex2f(-4.0, 0.0);

    glVertex2f(10.0, 5.0);
    glVertex2f(10.0, 0.0);
    glVertex2f(7.0, 5.0);
    glVertex2f(7.0, 0.0);
    glVertex2f(4.0, 5.0);
    glVertex2f(4.0, 0.0);

    glVertex2f(-0.90, 5.0);
    glVertex2f(-0.90, -2.0);
    glVertex2f(0.90, 5.0);
    glVertex2f(0.90, -2.0);
    glEnd();
//door handle

   glColor3f(1.0f, 1.0, 1.0);
    drawCircle(1.25, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(0.75, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-1.25, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-0.75, 2.0, 0.09, 100);
    glColor3f(0.4f, 0.4, 0.4);
    drawCircle(0.0, 17.0, 0.75, 100);
    glColor3f(0.6f, 0.9, 1.0);
    drawCircle(0.0, 17.0, 0.7, 100);

    glEnd();

//upper

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-35.0, 25.0);
    glVertex2f(-18.00, 22.0);
    glVertex2f(-18.00, 24.30);
    glVertex2f(-35.0, 28.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-35.0, 25.0);
    glVertex2f(-17.50, 22.0);
    glVertex2f(-17.50, 19.30);
    glVertex2f(-35.0, 21.30);
    glEnd();




    //right
    ///right aiub building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(35.0, 23.0);
    glVertex2f(18.0, 20.0);
    glVertex2f(18.0, -2.0);
    glVertex2f(35.0, -8.0);
    glEnd();


    glLineWidth(16.50);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 1.0f);
     glVertex2f(35.0, 5.20);
    glVertex2f(17.50, 6.70);
    glVertex2f(17.50, 19.70);
    glVertex2f(35.0, 20.80);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(35.0, 8.50);
    glVertex2f(17.50, 8.50);
     glVertex2f(35.0, 7.00);
    glVertex2f(17.50, 7.00);
 glVertex2f(18.50, 24.20);
    glVertex2f(35.0, 27.90);


    glEnd();

 glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
     glVertex2f(35.0, 18.0);
    glVertex2f(18.80, 16.50);
    glVertex2f(18.80, 12.50);
    glVertex2f(35.0, 13.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(35.0, 2.0);
    glVertex2f(18.80, 4.0);
    glVertex2f(18.80, 0.70);
    glVertex2f(35.0, -4.20);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(35.0, 10.70);
    glVertex2f(18.0, 10.70);
     glColor3f(0.5f, 0.5f, 0.9f);

    glVertex2f(35.0, 15.0);
    glVertex2f(18.80, 15.0);
    glVertex2f(35.0, -1.5);
    glVertex2f(18.80, 2.0);
//window
       glVertex2f(34.0, 17.80);
    glVertex2f(34.0, 13.0);
      glVertex2f(28.0, 17.50);
    glVertex2f(28.0, 12.80);
      glVertex2f(21.0, 17.0);
    glVertex2f(21.0, 12.60);

    glVertex2f(34.0, 2.10);
    glVertex2f(34.0, -4.10);
    glVertex2f(28.0, 3.0);
    glVertex2f(28.0, -2.10);
    glVertex2f(21.0, 4.0);
    glVertex2f(21.0, 0.0);

     glVertex2f(18.0, -2.0);
    glVertex2f(35.0, -8.0);

    glEnd();

//upper

         glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(35.0, 25.0);
    glVertex2f(18.00, 22.0);
    glVertex2f(18.00, 24.30);
    glVertex2f(35.0, 28.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(35.0, 25.0);
    glVertex2f(17.50, 22.0);
    glVertex2f(17.50, 19.30);
    glVertex2f(35.0, 21.30);
    glEnd();

///human
 glPushMatrix();
    glTranslatef(moveN3,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-28.00f, -1.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-28.45, -1.5);
glVertex2f(-27.55, -1.50);
glVertex2f(-27.55, -3.50);
glVertex2f(-28.45, -3.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(6.50);
glBegin(GL_LINES);
glVertex2f(-28.20, -3.50);
glVertex2f(-28.20, -5.30);

glVertex2f(-27.80, -3.50);
glVertex2f(-27.80, -5.30);
glEnd();

glPopMatrix();
glPopMatrix();

//second human
 glPushMatrix();
    glTranslatef(moveN4,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-19.00f, -5.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.50, 0.0);
glBegin(GL_QUADS);
glVertex2f(-19.45, -5.5);
glVertex2f(-18.55, -5.50);
glVertex2f(-18.55, -7.50);
glVertex2f(-19.45, -7.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(-19.20, -7.50);
glVertex2f(-19.20, -9.30);

glVertex2f(-18.80, -7.50);
glVertex2f(-18.80, -9.30);
glEnd();
glPopMatrix();
glPopMatrix();

//third human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(18.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.6, 0.2, 0.1);
glBegin(GL_QUADS);
glVertex2f(18.45, -0.5);
glVertex2f(17.55, -0.50);
glVertex2f(17.55, -2.50);
glVertex2f(18.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(18.20, -2.50);
glVertex2f(18.20, -4.30);

glVertex2f(17.80, -2.50);
glVertex2f(17.80, -4.30);
glEnd();
//fourth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(17.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.5, 0.3);
glBegin(GL_QUADS);
glVertex2f(17.45, -0.5);
glVertex2f(16.55, -0.50);
glVertex2f(16.55, -2.50);
glVertex2f(17.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(17.20, -2.50);
glVertex2f(17.20, -4.30);

glVertex2f(16.80, -2.50);
glVertex2f(16.80, -4.30);
glEnd();
//fifth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(9.00f, -7.60, 0.35f, 100);
    glEnd();

//body
glColor3f(0.8, 0.0, 0.7);
glBegin(GL_QUADS);
glVertex2f(9.45, -8.1);
glVertex2f(8.55, -8.10);
glVertex2f(8.55, -10.10);
glVertex2f(9.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(9.20, -10.10);
glVertex2f(9.20, -11.90);

glVertex2f(8.80, -10.10);
glVertex2f(8.80, -11.90);
glEnd();
//sixth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(10.00f, -7.60f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.7, 0.3, 0.0);
glBegin(GL_QUADS);
glVertex2f(10.45, -8.1);
glVertex2f(9.55, -8.1);
glVertex2f(9.55, -10.10);
glVertex2f(10.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(10.20, -10.10);
glVertex2f(10.20, -11.90);

glVertex2f(9.80, -10.10);
glVertex2f(9.80, -11.90);
glEnd();

 ///name of school

    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-21.4f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "AIUB");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(19.0f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "AIUB");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-32.7f, 22.4f, GLUT_BITMAP_TIMES_ROMAN_10, "D-BUILDING");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(28.7f, 22.4f, GLUT_BITMAP_TIMES_ROMAN_10, "C-BUILDING");
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-32.7f, 7.85, GLUT_BITMAP_8_BY_13, "where leaders are created");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(22.7f, 7.85, GLUT_BITMAP_8_BY_13, "where leaders are created");
    glColor3f(0.0f, 0.0f, 0.0f);
renderBitmapString(-9.0f, 14.0f, GLUT_BITMAP_8_BY_13, "American International University Bangladesh-AIUB");
    glEnd();

///Bus 01
    glPushMatrix();
    glTranslatef(moveW , 0.0f , 0.0f);
    glLineWidth(0.5);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-11.90, -23.50);
    glVertex2f(-7.10, -23.50);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-12.00, -24.00);

    glColor3f(0.7, 0.7, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -24.00);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-12.00, -25.00);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -25.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-7.00, -26.50);
    glVertex2f(-12.00, -26.50);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-11.00f, -24.0f);
    glVertex2f(-11.00f, -25.05f);
    glVertex2f(-10.00f, -24.0f);
    glVertex2f(-10.00f, -25.05f);
    glVertex2f(-9.00f, -24.0f);
    glVertex2f(-9.00f, -25.05f);
    glVertex2f(-8.0f, -24.0f);
    glVertex2f(-8.0f, -25.05f);
    glEnd();

    //wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-7.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-7.80f, -26.30f, 0.25f, 100);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-10.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.80f, -26.30f, 0.25f, 100);
    glEnd();

    glPopMatrix();

    ///human

 if (isVisible)
    {

glPushMatrix();
glTranslatef(0.0f, moveMM2, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(0.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(-0.50, -28.5);
glVertex2f(0.50, -28.50);
glVertex2f(0.50, -30.50);
glVertex2f(-0.50, -30.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-0.19, -30.50);
glVertex2f(-0.19, -32.50);
glEnd();

glBegin(GL_LINES);
glVertex2f(0.21, -30.50);
glVertex2f(0.21, -32.50);
glEnd();

glPopMatrix();
glPopMatrix();
    }
     if (extraObjectVisible) // Draw extra object when visible
    {
        glPushMatrix();
glTranslatef(0.0f, moveMM2, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(0.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(-0.50, -28.5);
glVertex2f(0.50, -28.50);
glVertex2f(0.50, -30.50);
glVertex2f(-0.50, -30.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-0.19, -30.50);
glVertex2f(-0.19, -32.50);
glVertex2f(0.21, -30.50);
glVertex2f(0.21, -32.50);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.80, -27.10);
glVertex2f(0.0, -26.60);
glVertex2f(0.80, -27.10);
glVertex2f(0.0, -27.60);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.50, -28.5);
glVertex2f(-0.20, -28.50);
glVertex2f(-0.30, -32.50);
glVertex2f(-0.50, -32.50);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(0.50, -28.5);
glVertex2f(0.20, -28.50);
glVertex2f(0.30, -32.50);
glVertex2f(0.50, -32.50);
glEnd();

glLineWidth(1.50);
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 0.0);
glVertex2f(-0.50, -27.20);
glVertex2f(-0.50, -28.0);
glEnd();

glPopMatrix();
glPopMatrix();
    }
glutSwapBuffers();
 }
void updateC(int value)
{
    if(moveC > +65)
    {
        moveC = -65;
    }
    moveC += 0.15;

    glutTimerFunc(60, updateC, 0);
    glutPostRedisplay();
}
void updateB(int value)
{
    if (moveB >20)
    {
        moveB = -10.0;
    }
    moveB += 0.15;
    glutTimerFunc(30, updateB, 0);
    glutPostRedisplay();
}
void updateN4(int value) {
    if (moveN4 < -11.0f)
        moveN4 = 5.0f;
    moveN4 -= 0.15;

    glutTimerFunc(60, updateN4, 0);
        glutPostRedisplay();

}
void updateN3(int value)
{
    if(moveN3 > 16)
    {
        moveN3 = 2;
    }
    moveN3 += 0.15;
    glutTimerFunc(60, updateN3, 0);
    glutPostRedisplay();
}
void updateW(int value)
{

    if(moveW > 50)
    {
        moveW = -35;
    }

    moveW += 0.16;

    glutTimerFunc(20, updateW, 0);

    glutPostRedisplay();
}


void updateMM2(int value)
{
    if (isVisible)
    {
        if (movingDown)
        {
            moveMM2 -= 0.15;
            if (moveMM2 <= -5) // Back and stop position
            {   extraObjectVisible = false; // Show the extra object
                isVisible = false;  // Hide the object
                movingDown = false; // Prepare to move up next
                glutTimerFunc(4000, updateMM2, 0); // Delay before reappearing
                return;
            }
        }
        else
        {
            moveMM2 += 0.15;
            if (moveMM2 >= 30) // Up and vanish
            {
                isVisible = false;  // Hide the object
                movingDown = true;  // Prepare to move down next
                extraObjectVisible = false; // Show the extra object
                glutTimerFunc(6000, updateMM2, 0); // Delay before reappearing
                return;
            }
        }
    }
    else
    {
        if (movingDown)
        {
            extraObjectVisible = true; // Show the extra object
            moveMM2 = 30;  // Start for turn back
            isVisible = false; // Now make it visible after delay

        }
        else
        {

        extraObjectVisible = false; // Show the extra object

          moveMM2 = -10; // Start position
        }

        isVisible = true; // Now make it visible after delay
    }

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(30, updateMM2, 0); // Keep updating
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
    glutCreateWindow("Scene Switch Example");

    init();
    glutTimerFunc(100, updateC, 1);
    glutTimerFunc(100, updateB, 0);
    glutTimerFunc(0, updateMM2, 1);
    glutTimerFunc(100, updateN4, 0);
    glutTimerFunc(100, updateN3, 0);
    glutTimerFunc(100, updateW, 1);


    glutDisplayFunc(universityLife);
    sndPlaySound("bird.wav", SND_ASYNC);  //youtube section
    glutMainLoop();
    return 0;
}

