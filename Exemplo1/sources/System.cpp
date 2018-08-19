#include "../headers/System.h"

System::System(int width, int height) {
	this->WIDTH = width;
	this->HEIGHT = height;
}

System::~System() {
}


int System::GLFWInit() {
	glfwInit();
	window = glfwCreateWindow(this->WIDTH, this->HEIGHT, "Exemplo1", NULL, NULL);  

	if (!window) { 
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");   
		glfwTerminate();   
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	// inicia manipulador da extensão GLEW  
	glewExperimental = GL_TRUE;  
	glewInit();

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed no init GLEW.");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int System::OpenGLSetup() {
	return 0;
}

int System::SystemSetup() {
	return 0;
}

void System::run() {

}

void System::finish() {

}
