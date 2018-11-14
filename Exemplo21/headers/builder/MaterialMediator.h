#ifndef MATERIAL_MEDIATOR_H
#define MATERIAL_MEDIATOR_H

#include <GLM/glm.hpp>
#include "../handler/MaterialHandler.h"

class MaterialMediator {

    MaterialHandler* materialHandler;
	Material* currentMaterial;

public:
    MaterialMediator(MaterialHandler* mesh);
    ~MaterialMediator();

    void callbackKAmbient(glm::vec3* ka);
    void callbackKDiffusse(glm::vec3* kd);
    void callbackKSpecular(glm::vec3* ks);
    void callbackNShinness(float ns);
	void callbackNewMaterial(string name);

};

#endif
