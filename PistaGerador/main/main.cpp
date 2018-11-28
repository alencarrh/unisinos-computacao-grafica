#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM/gtc/matrix_transform.hpp>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
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
GLuint VAO, VBO_VERTICE, VBO_COLOR; //ignorar VBO_COLOR por enquanto
glm::vec3* control_points_color = new glm::vec3(1.0f, 0.0f, 0.0f); //RED

// others attributes
vector<float> control_points;
ShaderHandler* shader;

//control attributes
double x_last_pos = -1.0, y_last_pos = -1.0;

//methods
int init();
int define_callbacks(GLFWwindow* window);
int load_shaders();
void gen_and_bind_vao();
void gen_and_configure_vbo_control_points();
void finish(GLFWwindow* window);
void update_vbo_vertice();
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
    gen_and_bind_vao();
    gen_and_configure_vbo_control_points();
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
	glEnable(GL_POINT_SMOOTH);


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

void gen_and_bind_vao() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
}

void gen_and_configure_vbo_control_points() {
    glGenBuffers(1, &VBO_VERTICE);
}


void update_vbo_vertice() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO_VERTICE);
    glBufferData(GL_ARRAY_BUFFER, control_points.size() * sizeof(float), control_points.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
}

void draw() {
    glPointSize(10);
    glDrawArrays(GL_POINTS, 0, (float)control_points.size() / 2);

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

        update_vbo_vertice();
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
	glDeleteBuffers(1, &VBO_VERTICE);
	glDeleteVertexArrays(1, &VAO);
}
