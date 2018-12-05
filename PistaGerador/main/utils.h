#ifndef UTILS
#define UTILS
#define _USE_MATH_DEFINES
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM/gtc/matrix_transform.hpp>
#include <ostream>
#include <iostream>
#include <fstream>  
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

//window attributes 
GLFWwindow* window;
string TITLE = "Gerador Pista - GB";
float WIDTH = 600.0;
float HEIGHT = 600.0;

//others
glm::mat4 projection;
//- control attributes
double x_last_pos = -1.0, y_last_pos = -1.0;


//callbacks
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

/**
 * Método que vai inicializar a GLFW e criar a janela
 */
int init() {
    if (!glfwInit()) {
        std::cout << "ERROR: Could not start GLFW3" << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WIDTH, HEIGHT, TITLE.c_str(), NULL, NULL);

    if (!window) {
        std::cout << "ERROR: Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();

    projection = glm::ortho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f, 1.0f);

    return EXIT_SUCCESS;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int define_callbacks(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    return EXIT_SUCCESS;
}

bool keep_running(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void clear_screen() {
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void del_vao(GLuint& vao) {
    glDeleteVertexArrays(1, &vao);
}

void del_vbo(GLuint& vbo) {
    glDeleteBuffers(1, &vbo);

}

void gen_vao(GLuint& vao) {
    glGenVertexArrays(1, &vao);
}

void gen_vbo(GLuint& vbo) {
    glGenBuffers(1, &vbo);
}

void bind_vao(GLuint& vao) {
    glBindVertexArray(vao);
}

void bind_vbo(GLuint& vao, GLuint& vbo, vector<float>& values) {
    bind_vao(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, values.size() * sizeof(float), values.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
}


float calculate_bspline_point(float& t, float& t_pow_3, float& t_pow_2, float& p1, float& p2, float& p3, float& p4) {

    float new_point =
    (
        (
            (-1 * t_pow_3 + 3 * t_pow_2 - 3 * t + 1) * p1 +
            (+3 * t_pow_3 - 6 * t_pow_2 + 0 * t + 4) * p2 +
            (-3 * t_pow_3 + 3 * t_pow_2 + 3 * t + 1) * p3 +
            (+1 * t_pow_3 + 0 * t_pow_2 + 0 * t + 0) * p4
        )
        / 6.0f
    );

    return new_point;
}


#endif
