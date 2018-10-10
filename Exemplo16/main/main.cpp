#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Cube.h"

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo14 - Adicionado textureas


*/

int main() {
    Scene* scene = new Scene(600, 600, "Simple Cube with textures");
    scene->addObj(new Cube());

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
