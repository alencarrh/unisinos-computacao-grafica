#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */

#include <iostream>
using namespace std;


/*

Este código é baseado no tutorial learnopengl.com 

*/


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void initVAOs();
void render();

int shaderProgram;
unsigned int VAO;
unsigned int VBO;


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
   // glViewport(0, 0, 800, 00);
	glewExperimental = GL_TRUE;
	glewInit();

    // callback para quando a janela é redimensionada
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // Pode ser desabilito o redimensionamento com o código abaixo
    // glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );



	initVAOs();





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
	
    // optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	// glDeleteBuffers(1, &VBO);


    glfwTerminate();
    return 0;
}

void render() {
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void initVAOs() {

	// 0. copy our vertices array in a buffer for OpenGL to use
	// 1. then set the vertex attributes pointers
	// 2. use our shader program when we want to render an object
	// 3. draw the object 



	/*
	  *
	  * VERTEX SHADER
	  *
	*/
	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec3 aPos;"
		"void main() {"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
		"}";

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


    /*
	  *
	  * FRAGMENT SHADER
	  *
    */

	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;"
		"void main()	{"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
		"}";

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


    /*
      *
      * SHADER PROGRAM
      *
    */

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	//Depois de fazer o link, não precisamos mais destes objetos
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// glUseProgram(shaderProgram);

	float vertices[] = {
	  -0.5f, -0.5f, 0.0f, // left  
	   0.5f, -0.5f, 0.0f, // right 
	   0.0f,  0.5f, 0.0f  // top   
	};

	glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	// 1. bind Vertex Array Object
	glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
