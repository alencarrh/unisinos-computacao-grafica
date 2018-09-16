#include "../headers/System.h"
#include "../headers/HelloTriangle.h"


/*

Este código é baseado no tutorial learnopengl.com

Continuação do exemplo2

*/

int main() {

    HelloTriangle* tringle = new HelloTriangle(600, 600, "LearnOpenGL");

    System* system = new System(tringle);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }

    system->run();

}
