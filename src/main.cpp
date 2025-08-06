#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.hpp"


void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow *window);


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const float TRIANGLE_VERTICES[] = {
    // Positions        // Colors
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f,   // Top right
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // Bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // Bottom left
    -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // Top left
};

const unsigned int TRIANGLE_INDICES[] = {
    0, 1, 3,
    1, 2, 3 
};


int main() {

    GLFWwindow* window;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
                
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // The book uses OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Learn OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    Shader shader("src/shaders/triangle.vs", "src/shaders/triangle.fs");


    GLuint vertexArrObj, vertexBuffObj, elementBuffObj;
    glGenVertexArrays(1, &vertexArrObj);
    glBindVertexArray(vertexArrObj);
    glGenBuffers(1, &vertexBuffObj);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE_VERTICES), TRIANGLE_VERTICES, GL_STATIC_DRAW);
    glGenBuffers(1, &elementBuffObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(TRIANGLE_INDICES), TRIANGLE_INDICES, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    while (!glfwWindowShouldClose(window)) {
        
        ProcessInput(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Use();

        glBindVertexArray(vertexArrObj);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    window;
    glViewport(0, 0, width, height);
}

void ToggleWireframeMode() {
    static bool wireframeMode = false;
    wireframeMode = !wireframeMode;
    glPolygonMode(GL_FRONT_AND_BACK, wireframeMode ? GL_LINE : GL_FILL);
}

void ProcessInput(GLFWwindow *window) {
    
    static bool isHoldingWireframe = false;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS && !isHoldingWireframe) {
        isHoldingWireframe = true;
        ToggleWireframeMode();
    }
    else if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_RELEASE) {
        isHoldingWireframe = false;
    }
}
