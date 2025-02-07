#include <windows.h>
#include <GL/glut.h>

void display() {

    glClearColor(0.5, 0.5, 0.5, 1.0); // Gray background
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Red

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(1.0f, 0.0f);    // x, y

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(0.0f, 1.0f);    // x, y

    glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(-1.0f, 0.0f);    // x, y

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(0.0f, -1.0f);

	glEnd();

	glFlush();  // Render nowglClear(GL_COLOR_BUFFER_BIT);


    // Draw the red triangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7, 0.6);
        glVertex2f(-0.5, 0.3);
        glVertex2f(-0.9, 0.3);
    glEnd();

    // Draw the yellow hexagon
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glBegin(GL_POLYGON);
        glVertex2f(0.4, 0.6);
        glVertex2f(0.6, 0.6);
        glVertex2f(0.7, 0.4);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.3, 0.4);
    glEnd();

    // Draw the green square
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_QUADS);
       glVertex2f(-0.8, -0.5);  // Bottom-left
       glVertex2f(-0.5, -0.5);  // Bottom-right
       glVertex2f(-0.5, -0.8);  // Top-right
       glVertex2f(-0.8, -0.8);  // Top-left

    glEnd();

    // Draw the orange triangle
    glColor3f(1.0, 0.5, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
        glVertex2f(0.6, -0.4);
        glVertex2f(0.7, -0.8);
        glVertex2f(0.5, -0.8);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.5, 0.5, 0.5, 1.0); // Gray background
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
