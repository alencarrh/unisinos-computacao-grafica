#ifndef MESH_MEDIATOR_H
#define MESH_MEDIATOR_H

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
    
    //values callback
	void callbackMaterialFile(string material);
    void callbackMaterialName(string name);
    void callbackNormal(glm::vec3* normal);
    void callbackTexture(glm::vec2* texture);
    void callbackVertice(glm::vec3* vertice);
};

#endif