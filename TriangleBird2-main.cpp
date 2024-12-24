#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;
GLuint VBO, VAO, shader;
int totalVertices = 0;

// Vertex Shader code
static const char* vShader = "\n\
#version 330\n\
layout(location = 0) in vec2 pos;\n\
void main()\n\
{\n\
    gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);\n\
}";

// Fragment Shader
static const char* fShader = "\n\
#version 330\n\
out vec4 colour;\n\
void main()\n\
{\n\
    colour = vec4(0.0, 0.3, 1.0, 1.0); // Blue color\n\
}";

void CreateTriangleBird(){
    GLfloat vertices[] = {
        // Triangle A
        0.0f, 0.0f, 0.2f, 0.0f, 0.1f, 0.2f,
        // Triangle B
        0.11f, 0.21f, 0.21f, 0.01f, 0.35f, 0.25f,
        // Triangle C
        0.0f, -0.01f, 0.2f, -0.01f, 0.17f, -0.15f,
        // Triangle D
        0.18f, -0.15f, 0.32f, -0.25f, 0.21f, -0.02f,
        // Triangle E
        -0.01f, 0.01f, 0.04f, 0.11f, -0.11f, 0.14f,
        // Triangle F
        -0.15f, 0.07f, -0.08f, 0.09f, -0.11f, 0.14f
    };
    totalVertices = sizeof(vertices) / sizeof(vertices[0]);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Create and bind VAO and VBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define vertex attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void AddShader(GLuint program, const char* code, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, NULL); 
    glCompileShader(shader);
    glAttachShader(program, shader); 
    glDeleteShader(shader);
}

void CompileShaders() {
    shader = glCreateProgram();
    AddShader(shader, vShader, GL_VERTEX_SHADER);
    AddShader(shader, fShader, GL_FRAGMENT_SHADER);
    glLinkProgram(shader); 
    glValidateProgram(shader);
}

int main() {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle Bird", NULL, NULL);
    if (!window) { 
        glfwTerminate(); 
        return -1; 
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        exit(EXIT_FAILURE);
    }

    glClearColor(0.8f, 0.898f, 1.0f, 1.0f);

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glViewport(0, 0, bufferWidth, bufferHeight);

    CreateTriangleBird();
    CompileShaders();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, totalVertices);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
