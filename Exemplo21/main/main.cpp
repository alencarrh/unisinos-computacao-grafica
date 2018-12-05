#include <vector>
#include <stdio.h>
#include "../headers/system/System.h"
#include "../headers/model/Scene.h"
#include "../headers/model/Object.h"
#include "../headers/model/Car.h"


int main() {
    Light* light = new Light();
    light->position = new glm::vec3(0.0f, 20.0f, 0.0f);
    light->color = new glm::vec3(1.0f, 1.0f, 1.0f);

    light->ambient = new glm::vec3(0.6f, 0.6f, 0.6f);
    light->diffuse = new glm::vec3(1.0f, 1.0f, 1.0f);
    light->specular = new glm::vec3(1.5f, 1.5f, 1.5f);

    Scene* scene = new Scene(600, 600, "All lights - refactoring code/structure");

    // scene->addObj(new Object("cenaPaintball.obj", new glm::vec3(0.0f, 0.0f, 30.0f)));
    // scene->addObj(new Object("trout.obj", new glm::vec3(0.0f, 0.0f, 5.0f)));
    // scene->addObj(new Object("mesa01.obj", new glm::vec3(0.0f, 0.0f, 5.0f)));
    scene->addObj(new Car("bmw.obj", "curva.txt"));
    scene->addObj(new Object("pista.obj", new glm::vec3(0.0f, 0.0f, 0.0f)));
    // scene->addObj(new Object("teapot.obj", new glm::vec3(-20.0f, 0.0f, 5.0f)));
    // scene->addObj(new Object("spider_pumpkin_obj.obj", new glm::vec3(-5.0f, -5.0f, 5.0f)));

    scene->setLight(light);

    System* system = new System(scene);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }


    system->run();

}
