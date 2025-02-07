#include <windows.h>
#include <GL/glut.h>

void display() {

    glClearColor(0.2, 0.4, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -1.0f);



//First Star without filled

	glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.25, -0.3);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.75, -0.3);

    glVertex2f(-0.75, -0.3);
    glVertex2f(-0.1, 0.2);

    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.9f, 0.2f);

    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.9f, 0.2f);

    glVertex2f(-0.9f, 0.2f);
    glVertex2f(-0.25, -0.3);



//Second star cover with black line

	glVertex2f(0.5f, 0.5f);
    glVertex2f(0.6f, 0.2f);

    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.9f, 0.2f);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.4f, 0.2f);

    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.1, 0.2);

    glVertex2f(0.1, 0.2);
    glVertex2f(0.35, 0.02);

    glVertex2f(0.35, 0.02);
    glVertex2f(0.25, -0.3);

    glVertex2f(0.25, -0.3);
    glVertex2f(0.5, -0.1);

    glVertex2f(0.5, -0.1);
    glVertex2f(0.75, -0.3);

   glVertex2f(0.75, -0.3);
   glVertex2f(0.5, -0.1);

    glVertex2f(0.75, -0.3);
    glVertex2f(0.65, 0.02);

   glVertex2f(0.65, 0.02);
   glVertex2f(0.9f, 0.2f);
	glEnd();
	glFlush();


/* red triangle
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.4, 0.2);
    glEnd();


//red triangle
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.9, 0.2);
        glVertex2f(-0.65, 0.02);
    glEnd();

//red triangle
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.4, 0.2);
        glVertex2f(-0.1, 0.2);
        glVertex2f(-0.35, 0.02);
    glEnd();

//red triangle
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.65, 0.02);
        glVertex2f(-0.75, -0.3);
        glVertex2f(-0.5, -0.1);
    glEnd();

//red triangle
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.35, 0.02);
        glVertex2f(-0.25, -0.3);
        glVertex2f(-0.5, -0.1);
    glEnd();

//red hexagon
    glColor4f(0.0, 0.0, 0.0, 0.0); // Orange color
    glBegin(GL_POLYGON);
        glVertex2f(-0.4, 0.2);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.65, 0.02);
        glVertex2f(-0.5, -0.1);
        glVertex2f(-0.35, 0.02);
    glEnd();

*/


//Orange triangle
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.4, 0.2);
    glEnd();


//Orange triangle
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.9, 0.2);
        glVertex2f(0.65, 0.02);
    glEnd();

//Orange triangle
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.1, 0.2);
        glVertex2f(0.35, 0.02);
    glEnd();

//Orange triangle
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.65, 0.02);
        glVertex2f(0.75, -0.3);
        glVertex2f(0.5, -0.1);
    glEnd();

//Orange triangle
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.35, 0.02);
        glVertex2f(0.25, -0.3);
        glVertex2f(0.5, -0.1);
    glEnd();

//Orange hexagon
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.65, 0.02);
        glVertex2f(0.5, -0.1);
        glVertex2f(0.35, 0.02);
    glEnd();

    glFlush();



}

void init() {
    glClearColor(0.2, 0.4, 0.4, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vertex, Primitive & Color");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
