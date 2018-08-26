#include "../headers/Triangulos.h"

Triangulos::Triangulos(int width, int height, char* screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;
}

Triangulos::~Triangulos() { }

int Triangulos::init(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    shader = new Shader("./shaders/core/vertex.vert", "./shaders/core/fragment.frag");
    shaderWhite = new Shader("./shaders/core/vertex.vert", "./shaders/core/fragment_white.frag");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
        // positions         // colors
        0.0f, 0.4f, 0.0f, 1.0f, 0.0f, 0.0f, // top 
        0.3f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //bottom middle
        0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom right
        -0.7f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f // bottom left
    };

    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        0, 1, 2 // second triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);


    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    return EXIT_SUCCESS;
}

void Triangulos::run(GLFWwindow* window) {
    processInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader->use();
    //shader->setFloat("xOffSet", 0.3f);
    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0);

	shaderWhite->use();
	glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);


}

bool Triangulos::keepRunning(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void Triangulos::finish() {
    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

int Triangulos::width() {
    return this->WIDTH;
}

int Triangulos::height() {
    return this->HEIGHT;
}

char* Triangulos::screenTitle() {
    return this->SCREEN_TITLE;
}


void Triangulos::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Triangulos::processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
