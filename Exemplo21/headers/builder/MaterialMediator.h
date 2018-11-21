#ifndef MATERIAL_MEDIATOR_H
#define MATERIAL_MEDIATOR_H

#include <GLM/glm.hpp>
#include "../data/Material.h"
#include "../handler/MaterialHandler.h"

class MaterialMediator {

private:
    MaterialHandler* materialHandler;
    Material* currentMaterial;

public:
    MaterialMediator(MaterialHandler* mesh);
    ~MaterialMediator();

    void callbackKAmbient(glm::vec3* ka);
    void callbackKDiffuse(glm::vec3* kd);
    void callbackKSpecular(glm::vec3* ks);
    void callbackNShinness(float ns);
    void callbackNewMaterial(string name);
	void callbackTextureName(string name);

};

#endif
