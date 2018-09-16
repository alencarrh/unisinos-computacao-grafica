#include "../headers/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo10 - Estudando sistema de coordenadas e câmera - movimentando com teclado e mouse


*/

int main() {

    Cubo* cubo = new Cubo(600, 600, "Exemplo11 - Coordinate Systems and Camera");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
