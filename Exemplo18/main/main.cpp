#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Cube.h"
#include "../headers/model/Lamp.h"

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo16 - Diffuse lighting


*/

int main() {
    Scene* scene = new Scene(600, 600, "Diffuse  lighting");
    scene->addObj(new Cube());
    // scene->addObj(new Lamp());

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
