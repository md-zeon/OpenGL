#include <GL/freeglut.h>

void display()
{
    // Clear the color buffer to set the background color for the window. This ensures that any previous drawings are removed and the window is ready for new graphics to be rendered.
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the width of the line to be drawn. In this case, the line width is set to 5 units. This means that the line will be drawn with a thickness of 5 pixels on the screen, making it more visible and prominent.
    glLineWidth(5);
    // Begin the definition of a line primitive. GL_LINES indicates that the vertices specified between glBegin(GL_LINES) and glEnd() will be treated as pairs of vertices that define individual lines. Each pair of vertices will be connected to form a line segment.
    glBegin(GL_LINES);
        // Specify the first vertex of the line. The parameters (-0.5, 0) indicate the x and y coordinates of the vertex, respectively. In this case, the vertex is located at (-0.5, 0) in the coordinate system, which means it is positioned to the left of the origin (0, 0) along the x-axis.
        // This vertex will be the starting point of the line segment that will be drawn.
        glVertex2f(-0.5,0);
        // Specify the second vertex of the line. The parameters (0.5, 0) indicate the x and y coordinates of the vertex, respectively. In this case, the vertex is located at (0.5, 0) in the coordinate system, which means it is positioned to the right of the origin (0, 0) along the x-axis.
        // This vertex will be the ending point of the line segment that will be drawn. The line will be drawn from the first vertex (-0.5, 0) to the second vertex (0.5, 0), creating a horizontal line segment across the center of the window.
        glVertex2f(0.5,0);
    // End the definition of the line primitive. This function should be called after glBegin(GL_LINES) to indicate that the definition of the line is complete. It tells OpenGL that all the vertices for the line have been specified and that it can now process and render the line on the screen.
    glEnd();
    // Flush the OpenGL command buffer to ensure that all previously issued OpenGL commands are executed as quickly as possible. This is necessary to ensure that the drawing commands for the line are processed and the results are displayed on the screen. In this case, it ensures that the line defined by glVertex2f() is rendered on the screen after the display function is called.
    glFlush();
}

// Main function to set up the OpenGL environment and start the rendering loop
int main (int argc, char** argv) {
    // Initializes the GLUT library and processes any command-line arguments passed to the program. This function must be called before any other GLUT functions. It sets up the necessary environment for using GLUT and prepares it to handle events and create windows.
    glutInit(&argc, argv);
    // Sets the initial display mode for the window. In this case, it specifies that the window should use a single buffer (GLUT_SINGLE) and an RGB color model (GLUT_RGB). This means that the window will not use double buffering and will display colors using the RGB color model. The single buffer mode means that all drawing will be done directly to the screen, which can lead to flickering if the scene is complex, but is sufficient for simple drawings like a single line.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial size of the window to 800 pixels wide and 600 pixels high. This function should be called before creating the window to ensure that the window is created with the specified dimensions. The window will be large enough to display the line clearly.
    glutInitWindowSize(800, 600);
    // Creates a window with the specified title ("Line"). This function also makes the created window the current window for subsequent OpenGL commands. The title of the window will be displayed in the title bar of the window. This is where the line will be rendered when the display function is called.
    glutCreateWindow("Line");
    // Registers the display callback function (display) with GLUT. This function will be called whenever the window needs to be redrawn, such as when it is first created or when it is resized. The display function contains the code that defines what will be drawn on the screen, which in this case is a single line segment from (-0.5, 0) to (0.5, 0). By registering the display function, we ensure that it will be called automatically by GLUT whenever the window needs to be updated, allowing the line to be rendered on the screen.
    glutDisplayFunc(display);
    // Enters the GLUT event processing loop. This function will not return until the program is terminated. It continuously checks for events (such as keyboard input, mouse input, or window events) and calls the appropriate callback functions (like the display function) to handle those events. This is necessary for the program to respond to user interactions and to keep the window responsive. In this case, it will ensure that the display function is called to render the line on the screen whenever necessary.
    glutMainLoop();

    return 0;
}