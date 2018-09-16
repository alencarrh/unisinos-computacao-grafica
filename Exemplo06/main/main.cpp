#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo5 - Estudando sistema de coordenadas


*/

int main() {

    Cubo* cubo = new Cubo(600, 600, "Exemplo6 - Coordinate Systems - Part1");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
