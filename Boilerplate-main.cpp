#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

void triangleDemo(){
    glColor3f(0.0f, 0.3f, 1.0f); // Background Color
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);  // A
    glVertex2f(0.3f, 0.0f);  // B
    glVertex2f(0.15f, 0.3f); // C
    glEnd();
}

int main(void){
    GLFWwindow *window;

    

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Triangle Bird", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        exit(EXIT_FAILURE);
    }

    glClearColor(0.8f, 0.898f, 1.0f, 1.0f);

    // Set the viewport and orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        triangleDemo();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
