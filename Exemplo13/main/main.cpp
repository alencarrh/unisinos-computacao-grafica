#include "../headers//system/System.h"
#include "../headers/Cubo.h"
#include <vector>
#include <stdio.h>

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo12 - Estudando sistema de coordenadas e câmera - movimentando com teclado e mouse


*/

int main() {

    Cubo* cubo = new Cubo(600, 600, "Exemplo13 - Coordinate Systems and Camera - Letra A");
    
    System* system = new System(cubo);
    
    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }
    
    
    system->run();

}
