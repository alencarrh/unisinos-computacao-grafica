#ifndef TRIANGULOS_H
#define TRIANGULOS_H
#include "Runnable.h"
#include "Shader.h"
#include <ostream>
#include <iostream>


class Triangulos : public Runnable {
private:
    GLint WIDTH, HEIGHT;
    char* SCREEN_TITLE;

    //dados que o init() cria e o run() utiliza
    Shader* shader;
    unsigned int VAO;
    unsigned int VBO;
	unsigned int colorsVBO;
    unsigned int EBO;

    //callback and eventHandlers
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void processInput(GLFWwindow* window);

public:
	Triangulos(int width, int height, char* screenTitle);
    ~Triangulos();

    int init(GLFWwindow* window) override;
    void run(GLFWwindow* window) override;
    bool keepRunning(GLFWwindow* window) override;
    void finish() override;
    int width() override;
    int height() override;
    char* screenTitle() override;
};

#endif
