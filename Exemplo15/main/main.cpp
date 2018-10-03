#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Cube.h"

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo12 - Refatoração completa do código


*/

int main() {
    Scene* scene = new Scene(600, 600, "Refactor - Simple Cube");
    scene->addObj(new Cube());

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
