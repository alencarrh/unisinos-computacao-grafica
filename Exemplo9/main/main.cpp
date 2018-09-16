#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo8 - Estudando sistema de coordenadas e câmera


*/

int main() {

    Cubo* cubo = new Cubo(600, 600, "Exemplo9 - Coordinate Systems and Camera");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
