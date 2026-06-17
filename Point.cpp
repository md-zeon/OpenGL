#include <GL/freeglut.h>

// display function to render the point on the screen
void display() {
    // glClear() - Clears the screens and sets the background color to the specified color. In this case, it clears the color buffer, which is the area where the colors of the pixels are stored.
    // GL_COLOR_BUFFER_BIT is a flag that indicates that the color buffer should be cleared. This means that all the pixels in the color buffer will be set to the background color, effectively clearing the screen before drawing new graphics.
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the size of the point to be drawn. In this case, the point size is set to 10.0 units. This means that the point will be drawn as a square with sides of length 10.0 units, centered at the specified vertex position.
    // 10 units = 10 pixels on the screen, so the point will appear as a 10x10 pixel square.
    glPointSize(10.0); 
    // glBegin() - Begins the definition of a primitive or a group of like primitives. In this case, GL_POINTS indicates that the primitive being defined is a point. This means that the vertices specified between glBegin(GL_POINTS) and glEnd() will be treated as individual points to be drawn on the screen.
    glBegin(GL_POINTS);
        // glVertex2f() - Specifies a vertex in 2D space. The parameters (0.0f, 0.0f) indicate the x and y coordinates of the vertex, respectively. In this case, the vertex is located at the origin of the coordinate system (0, 0). Since GL_POINTS is used, this vertex will be drawn as a point on the screen at the specified coordinates.
        glVertex2f(0.0f, 0.0f);
    // glEnd() - Ends the definition of a primitive or a group of like primitives. This function should be called after glBegin() to indicate that the definition of the primitive is complete. In this case, it indicates that the point defined by glVertex2f() is complete and can be rendered on the screen.
    glEnd();
    // glFlush() - Flushes the OpenGL command buffer, ensuring that all previously issued OpenGL commands are executed as quickly as possible. This is necessary to ensure that the drawing commands are processed and the results are displayed on the screen. In this case, it ensures that the point defined by glVertex2f() is rendered on the screen after the display function is called.
    glFlush(); 
}

// main function to set up the OpenGL environment and start the rendering loop
int main (int argc, char** argv) {
    // Initializes the GLUT library and processes any command-line arguments passed to the program. This function must be called before any other GLUT functions. It sets up the necessary environment for using GLUT and prepares it to handle events and create windows.
    glutInit(&argc, argv);
    // Sets the initial display mode for the window. In this case, it specifies that the window should use a single buffer (GLUT_SINGLE) and an RGB color model (GLUT_RGB). This means that the window will not use double buffering and will display colors using the RGB color model. The single buffer mode means that all drawing will be done directly to the screen, which can lead to flickering if the scene is complex, but is sufficient for simple drawings like a single point.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial size of the window to 800 pixels wide and 600 pixels high. This function should be called before creating the window to ensure that the window is created with the specified dimensions. The window will be large enough to display the point clearly.
    glutInitWindowSize(800, 600);
    // Creates a window with the specified title ("Point"). This function also makes the created window the current window for subsequent OpenGL commands. The title of the window will be displayed in the title bar of the window. This is where the point will be rendered when the display function is called.
    glutCreateWindow("Point");
    // Registers the display callback function (display) with GLUT. This function will be called whenever the window needs to be redrawn, such as when it is first created or when it is resized. The display function contains the code that defines what will be drawn on the screen, which in this case is a single point at the origin. By registering the display function, we ensure that it will be called automatically by GLUT whenever the window needs to be updated, allowing the point to be rendered on the screen.
    glutDisplayFunc(display);
    // Enters the GLUT event processing loop. This function will not return until the program is terminated. It continuously checks for events (such as keyboard input, mouse input, or window events) and calls the appropriate callback functions (like the display function) to handle those events. This is necessary for the program to respond to user interactions and to keep the window responsive. In this case, it will ensure that the display function is called to render the point on the screen whenever necessary.
    glutMainLoop();
    
    return 0;
}