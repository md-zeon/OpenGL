#include <GL/freeglut.h> // import the freeglut library for OpenGL

// function to display the graphics
void display() { 
    // glClear() - Clears the screens and sets the background color to the specified color. In this case, it clears the color buffer, which is the area where the colors of the pixels are stored.
    // GL_COLOR_BUFFER_BIT is a flag that indicates that the color buffer should be cleared. This means that all the pixels in the color buffer will be set to the background color, effectively clearing the screen before drawing new graphics.
    glClear(GL_COLOR_BUFFER_BIT); 
    // Immediately executes all OpenGL commands in the pipeline, ensuring that the drawing commands are processed and the results are displayed on the screen.
    glFlush(); 
}

int main(int argc, char** argv) {
    // Initializes the GLUT library and processes any command-line arguments passed to the program. This function must be called before any other GLUT functions.
    glutInit(&argc, argv); 
    // Sets the initial display mode for the window. In this case, it specifies that the window should use a single buffer (GLUT_SINGLE) and an RGB color model (GLUT_RGB). This means that the window will not use double buffering and will display colors using the RGB color model.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Sets the initial size of the window to 800 pixels wide and 600 pixels high. This function should be called before creating the window to ensure that the window is created with the specified dimensions.
    glutInitWindowSize(800, 600);
    // Creates a window with the specified title ("My First OpenGL Program"). This function also makes the created window the current window for subsequent OpenGL commands. The title of the window will be displayed in the title bar of the window.
    glutCreateWindow("My First OpenGL Program");
    // Registers the display callback function (display) with GLUT. This function will be called whenever the window needs to be redrawn, such as when it is first created or when it is resized. The display function contains the code that defines what will be drawn on the screen.
    glutDisplayFunc(display);
    // Enters the GLUT event processing loop. This function will not return until the program is terminated. It continuously checks for events (such as keyboard input, mouse input, or window events) and calls the appropriate callback functions (like the display function) to handle those events. This is necessary for the program to respond to user interactions and to keep the window responsive.
    glutMainLoop();
    
    return 0;
}