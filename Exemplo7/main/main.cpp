#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo6 - Estudando sistema de coordenadas


*/

int main() {

    Cubo* cubo = new Cubo(600, 600, "Exemplo7 - Coordinate Systems - Part2");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
