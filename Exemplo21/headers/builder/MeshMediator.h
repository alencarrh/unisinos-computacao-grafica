#ifndef MEDIATOR_H
#define MEDIATOR_H

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
    MeshMediator(Mesh* mesh);
    ~MeshMediator();

    //data callback
    void callbackFace(Face* face);
    void callbackGroup(string name);
    void callbackMaterial(Material* material);

    //light callback
    void callbackKAmbiente(glm::vec3* ka);
    void callbackKDiffuse(glm::vec3* kd);
    void callbackKSpecular(glm::vec3* ks);
    void callbackNShininness(float ns);

    //values callback
    void callbackMaterialName(string name);
    void callbackNormal(glm::vec3* normal);
    void callbackTexture(glm::vec2* texture);
    void callbackVertice(glm::vec3* vertice);
};

#endif
