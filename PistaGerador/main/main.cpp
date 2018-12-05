#define _USE_MATH_DEFINES
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM/gtc/matrix_transform.hpp>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "../headers/ShaderHandler.h" //TODO mover para a mesma pasta

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

using namespace std;

//window attributes 
GLFWwindow* window;
string TITLE = "Gerador Pista - GB";
float WIDTH = 600.0;
float HEIGHT = 600.0;
glm::mat4 projection;

// VAO, VBOs attributes
GLuint VAO_PONTOS_CONTROLE, VBO_PONTOS_CONTROLE, VBO_COLOR; //ignorar VBO_COLOR por enquanto
GLuint VAO_B_SLINES, VAO_B_SLINES_EX, VAO_B_SLINES_IN;
GLuint VBO_B_SLINES, VBO_B_SLINES_EX, VBO_B_SLINES_IN;
glm::vec3* control_points_color = new glm::vec3(1.0f, 0.0f, 0.0f); //RED

// others attributes
vector<float> control_points, b_splines, b_splines_interna, b_splines_externa;
ShaderHandler* shader;

//control attributes
double x_last_pos = -1.0, y_last_pos = -1.0;

//methods
int init();
int define_callbacks(GLFWwindow* window);
int load_shaders();
void gen_and_bind_vao_pontos_controle();
void gen_and_configure_vbo_control_points();
void gen_and_bind_vao_b_splines();
void gen_and_configure_vbo_b_splines();
void finish(GLFWwindow* window);
void update_vbo_pontos_controle();
void update_vbo_b_splines();
void update_vbo_b_splines_external_internal();
void draw();

//control methods
bool keep_running(GLFWwindow* window);
void clear_screen();

//callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

//handlers
void keyboard_input_handler(GLFWwindow* window);


//main function
int main() {
    init();
    define_callbacks(window);
    load_shaders();
    gen_and_bind_vao_pontos_controle();
    gen_and_configure_vbo_control_points();
    gen_and_bind_vao_b_splines();
    gen_and_configure_vbo_b_splines();
    //gen_and_configure_vbo_color() ??

    while (keep_running(window)) {
        clear_screen();
        keyboard_input_handler(window);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    finish(window);
}

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

int define_callbacks(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    return EXIT_SUCCESS;
}

int load_shaders() {
    shader = new ShaderHandler("./shaders/core/vertex.vert", "./shaders/core/fragment.frag");

    if (!shader) {
        std::cout << "ERROR: Failed to load shaders" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    shader->use();
    shader->setVec3("control_points_color", control_points_color);
    shader->setMatrix4fv("projection", projection);

    return EXIT_SUCCESS;
}

void gen_and_bind_vao_pontos_controle() {
    glGenVertexArrays(1, &VAO_PONTOS_CONTROLE);
}

void gen_and_configure_vbo_control_points() {
    glGenBuffers(1, &VBO_PONTOS_CONTROLE);
}

void gen_and_bind_vao_b_splines() {
    glGenVertexArrays(1, &VAO_B_SLINES);
    glGenVertexArrays(1, &VAO_B_SLINES_EX);
    glGenVertexArrays(1, &VAO_B_SLINES_IN);
}

void gen_and_configure_vbo_b_splines() {
    glGenBuffers(1, &VBO_B_SLINES);
    glGenBuffers(1, &VBO_B_SLINES_IN);
    glGenBuffers(1, &VBO_B_SLINES_EX);
}

void update_vbo_pontos_controle() {
    glBindVertexArray(VAO_PONTOS_CONTROLE);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_PONTOS_CONTROLE);
    glBufferData(GL_ARRAY_BUFFER, control_points.size() * sizeof(float), control_points.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}


void update_vbo_b_splines() {
    // x y
    // 0 1
    // 2 3
    // 4 5
    // 6 7

    b_splines.clear();
    int size = control_points.size();

    for (int i = 0; i < size; i += 2) {
        for (float t = 0; t < 1; t += 0.05f) {

            float t_pow_3 = pow(t, 3);
            float t_pow_2 = pow(t, 2);
            float x =
            (
                (
                    (-1 * t_pow_3 + 3 * t_pow_2 - 3 * t + 1) * control_points[(i + 0) % size] +
                    (+3 * t_pow_3 - 6 * t_pow_2 + 0 * t + 4) * control_points[(i + 2) % size] +
                    (-3 * t_pow_3 + 3 * t_pow_2 + 3 * t + 1) * control_points[(i + 4) % size] +
                    (+1 * t_pow_3 + 0 * t_pow_2 + 0 * t + 0) * control_points[(i + 6) % size]
                )
                / 6.0f
            );

            float y =
            (
                (
                    (-1 * t_pow_3 + 3 * t_pow_2 - 3 * t + 1) * control_points[(i + 0) % size + 1] +
                    (+3 * t_pow_3 - 6 * t_pow_2 + 0 * t + 4) * control_points[(i + 2) % size + 1] +
                    (-3 * t_pow_3 + 3 * t_pow_2 + 3 * t + 1) * control_points[(i + 4) % size + 1] +
                    (+1 * t_pow_3 + 0 * t_pow_2 + 0 * t + 0) * control_points[(i + 6) % size + 1]
                )
                / 6.0f
            );

            b_splines.push_back(x);
            b_splines.push_back(y);

        }
    }


    glBindVertexArray(VAO_B_SLINES);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_B_SLINES);
    glBufferData(GL_ARRAY_BUFFER, b_splines.size() * sizeof(float), b_splines.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}


void update_vbo_b_splines_external_internal() {
    b_splines_externa.clear();
    b_splines_interna.clear();
    int size = b_splines.size();

    // if (control_points.size() < 7) {
        // return;
    // }

    for (int i = 0; i < size; i +=2) {

        double Ax = b_splines[(i + 0) % size];
        double Ay = b_splines[(i + 1) % size];
        double Bx = b_splines[(i + 2) % size];
        double By = b_splines[(i + 3) % size];

        double w = Bx - Ax;
        double h = By - Ay;
        double a = atan(h / w);

        float internalAngle, externalAngle;

        if (w < 0) {
            internalAngle = a + M_PI / 2;
            externalAngle = a - M_PI / 2;
        } else {
            internalAngle = a - M_PI / 2;
            externalAngle = a + M_PI / 2;
        }


        float internalCx = cos(internalAngle) * 15 + Ax;
        float internalCy = sin(internalAngle) * 15 + Ay;


        b_splines_interna.push_back(internalCx);
        b_splines_interna.push_back(internalCy);


        float externalCx = cos(externalAngle) * 15 + Bx;
        float externalCy = sin(externalAngle) * 15 + By;

        b_splines_externa.push_back(externalCx);
        b_splines_externa.push_back(externalCy);

    }


    glBindVertexArray(VAO_B_SLINES_EX);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_B_SLINES_EX);
    glBufferData(GL_ARRAY_BUFFER, b_splines_externa.size() * sizeof(float), b_splines_externa.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);


    glBindVertexArray(VAO_B_SLINES_IN);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_B_SLINES_IN);
    glBufferData(GL_ARRAY_BUFFER, b_splines_interna.size() * sizeof(float), b_splines_interna.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
}


void draw() {
    glBindVertexArray(VAO_PONTOS_CONTROLE);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, (float)control_points.size() / 2);

    // B-Splines
    glBindVertexArray(VAO_B_SLINES);
    glDrawArrays(GL_LINE_STRIP, 0, (float)b_splines.size() / 2);

    // B-Splines external
    glBindVertexArray(VAO_B_SLINES_EX);
    glDrawArrays(GL_LINE_STRIP, 0, (float)b_splines.size() / 2);

    // B-Splines internal
    glBindVertexArray(VAO_B_SLINES_IN);
    glDrawArrays(GL_LINE_STRIP, 0, (float)b_splines.size() / 2);


}

bool keep_running(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x_current_pos, y_current_pos;
        glfwGetCursorPos(window, &x_current_pos, &y_current_pos);

        if (x_last_pos == x_current_pos && x_last_pos == x_current_pos) {
            //just to not repeat
            return;
        }

        cout << "x: " << x_current_pos << "  y: " << y_current_pos << endl;
        x_last_pos = x_current_pos;
        y_last_pos = y_current_pos;
        control_points.push_back((float)x_current_pos);
        control_points.push_back((float)y_current_pos);

        update_vbo_pontos_controle();

        // if (control_points.size() > 7) {
        // cout << "update_vbo_b_splines" << endl;
        update_vbo_b_splines();
        update_vbo_b_splines_external_internal();

        // }


    }
}

void keyboard_input_handler(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void clear_screen() {
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void finish(GLFWwindow* window) {
    glDeleteBuffers(1, &VBO_PONTOS_CONTROLE);
    glDeleteVertexArrays(1, &VAO_PONTOS_CONTROLE);
}
