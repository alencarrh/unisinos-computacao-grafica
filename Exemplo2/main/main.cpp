#include "../headers/System.h"
#include "../headers/HelloTriangle.h"


/*

Este código é baseado no tutorial learnopengl.com

Código faz exatamente a mesma coisa que o Exemplo1, porém com o código estrutura diferente.

*/

int main() {

    HelloTriangle* tringle = new HelloTriangle(600, 600, "LearnOpenGL");

    System* system = new System(tringle);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }

    system->run();

}
