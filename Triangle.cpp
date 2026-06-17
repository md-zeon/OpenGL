#include <GL/freeglut.h>

void display()
{
    // Clear the color buffer to prepare for drawing
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        // Define the vertices of the triangle
        glVertex2f(0,0.5);

        glVertex2f(-0.5,-0.5);

        glVertex2f(0.5,-0.5);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize the GLUT library
    glutInit(&argc, argv);
    // Set the display mode to single buffer and RGB color
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the initial window size
    glutInitWindowSize(400, 400);
    // Create a window with the specified title
    glutCreateWindow("Triangle");
    // Set the display callback function to render the triangle
    glutDisplayFunc(display);
    // Enter the GLUT event processing loop
    glutMainLoop();
    return 0;
}