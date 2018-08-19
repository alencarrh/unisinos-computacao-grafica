#ifndef SYSTEM_H
#define SYSTEM_H

// Internal
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <math.h>


// External Libs
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <SOIL.h>

class System {

private:
	// Screen
	GLint WIDTH, HEIGHT;
	int screenWidth, screenHeight;

public:
	GLFWwindow * window;
	//Shader coreShader;

public:
	System(int width, int height);
	~System();

	int GLFWInit();
	int OpenGLSetup();
	int SystemSetup();

	void run();

	void finish();

};

#endif