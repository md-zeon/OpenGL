#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        glVertex2f(-0.5,0.5);

        glVertex2f(0.5,0.5);

        glVertex2f(0.5,-0.5);

        glVertex2f(-0.5,-0.5);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Rectangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}