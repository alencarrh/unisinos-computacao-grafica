#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Continuação da estrutura do Cubo.

*/

int main() {

    Cubo* cubo = new Cubo(800, 800, "Cubo!");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
