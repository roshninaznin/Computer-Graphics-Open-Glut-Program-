#include <windows.h>
#include <GL/glut.h>
#include <math.h>

# define PI 3.14159265358979323846

void drawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount) {
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.9f, -0.6f);
        glVertex2f(0.9f, -0.6f);
        glVertex2f(0.9f, 0.6f);
        glVertex2f(-0.9f, 0.6f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.25f, 100);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bangladesh Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
