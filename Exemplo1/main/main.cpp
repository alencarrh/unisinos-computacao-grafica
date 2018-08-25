#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */

#include <iostream>
using namespace std;


/*

Este código é baseado no tutorial learnopengl.com

*/


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void render();

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 00);


    // callback para quando a janela é redimensionada
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // Pode ser desabilito o redimensionamento com o código abaixo
    // glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );


    /* render loop
     * 1. check inputs
     * 2. render
     * 2.1. clear and then render
     * 3. swap buffers and poll events
    */
    while (!glfwWindowShouldClose(window)) {

        // check inputs
        processInput(window);

        // render

        // clear
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        render();

        // swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();


    }

    glfwTerminate();
    return 0;
}


void render() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
