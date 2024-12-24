#include <iostream>
#include <vector>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

struct vertex{ 
    GLfloat x; 
    GLfloat y;
};

void triangleBird(){
    vector<vector<vertex>> triangles;
    // Triangle Positions     A                 B                  C
    triangles.push_back({{0.0f, 0.0f},    {0.2f, 0.0f},     {0.1f, 0.2f}});     // A
    triangles.push_back({{0.11f, 0.21f},  {0.21f, 0.01f},   {0.35f, 0.25f}});   // B
    triangles.push_back({{0.0f, -0.01f},  {0.2f, -0.01f},   {0.17f, -0.15f}});  // C
    triangles.push_back({{0.18f, -0.15f}, {0.32f, -0.25f},  {0.21f, -0.02f}});  // D
    triangles.push_back({{-0.01f, 0.01f}, {0.04f, 0.11f},   {-0.11f, 0.14f}});  // E
    triangles.push_back({{-0.15f, 0.07f}, {-0.08f, 0.09f},  {-0.11f, 0.14f}});  // F



    glColor3f(0.0f, 0.3f, 1.0f); // Blue Color
    for(auto triangle : triangles){
        glBegin(GL_TRIANGLES);
        for(auto vertex : triangle){
            glVertex2f(vertex.x, vertex.y);
        }
        glEnd();
    }
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

        triangleBird();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
