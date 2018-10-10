#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Cube.h"
#include "../headers/model/Lamp.h"
#include "../headers/model/Mesa.h"

/*

    Este código é baseado no tutorial learnopengl.com
    

    Continuação do exemplo18 - Refatoração


*/

int main() {
    Light* light = new Light();
    light->position = new glm::vec3(0.0f, 3.0f, 0.0f);
    light->color = new glm::vec3(1.0f, 1.0f, 1.0f);

    light->ambient = new glm::vec3(0.1f, 0.1f, 0.1f);
    light->diffuse = new glm::vec3(0.7f, 0.7f, 0.7f);
    light->specular = new glm::vec3(1.2f, 1.2f, 1.2f);

    Scene* scene = new Scene(600, 600, "All lights - refactoring code/structure");
    scene->addObj(new Cube());
    // scene->addObj(new Mesa("cube.obj"));
    scene->setLight(light);

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
