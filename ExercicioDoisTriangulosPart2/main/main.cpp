#include "../headers/System.h"
#include "../headers/Triangulos.h"


/*

Este código é baseado no tutorial learnopengl.com

Continuação do exemplo4

*/

int main() {

	Triangulos* tringle = new Triangulos(600, 600, "LearnOpenGL");

    System* system = new System(tringle);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }

	// int nrAttributes;
	// glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	// std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    system->run();

}
