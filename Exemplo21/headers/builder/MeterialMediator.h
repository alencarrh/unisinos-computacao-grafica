#ifndef MATERIAL_MEDIATOR_H
#define MATERIAL_MEDIATOR_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../data/Face.h"
#include "../data/Group.h"
#include "../data/Material.h"
#include "../data/Mesh.h"

class MeshMediator {

    Mesh* mesh;

public:
    MeshMediator(MaterialHandler* mesh);
    ~MeshMediator();

    //data callback
    void callbackFace(Face* face);
    void callbackGroup(string name);
    void callbackMaterial(Material* material);

    //values callback
    void callbackMaterialName(string name);
    void callbackNormal(glm::vec3* normal);
    void callbackTexture(glm::vec2* texture);
    void callbackVertice(glm::vec3* vertice);
};

#endif
