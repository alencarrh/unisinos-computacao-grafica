#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Cube.h"
#include "../headers/model/Lamp.h"

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo18 - Refatoração


*/

int main() {
    Light* light = new Light();
    light->position = new glm::vec3(0.0f, 3.0f, 0.0f);
    light->color = new glm::vec3(1.0f, 1.0f, 1.0f);
    light->ambient = new glm::vec3(0.2f, 0.2f, 0.2f);
    light->diffuse = new glm::vec3(0.5f, 0.5f, 0.5f);
    light->specular = new glm::vec3(1.0f, 1.0f, 1.0f);

    Scene* scene = new Scene(600, 600, "All lights - refactoring code/structure");
    scene->addObj(new Cube());
    scene->setLight(light);

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
