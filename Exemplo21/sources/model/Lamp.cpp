#include "../../headers/model/Lamp.h"

Lamp::Lamp() {}

Lamp::~Lamp() {
    delete this->_mesh;
}

Face* createFace2(int v0, int v1, int v2, int v3, int normal) {
    Face* face = new Face();
    face->addVerticeId(v0);
    face->addVerticeId(v1);
    face->addVerticeId(v3);

    face->addVerticeId(v1);
    face->addVerticeId(v2);
    face->addVerticeId(v3);

    return face;
}

void Lamp::prepare() {

    this->_mesh = new Mesh("default");
    int A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7;
    float escale = 4;

    this->_mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, 1.0f / escale)); //A
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, 1.0f / escale)); //B
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, 1.0f / escale)); //C
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, 1.0f / escale)); //D      
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, -1.0f / escale)); //E
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, -1.0f / escale)); //F
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, -1.0f / escale)); //G
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, -1.0f / escale)); //H

    Group* group = new Group("default");
    group->addFace(createFace2(A, B, C, D, 4));
    group->addFace(createFace2(A, D, H, E, 0));
    group->addFace(createFace2(A, E, F, B, 2));
    group->addFace(createFace2(C, B, F, G, 1));
    group->addFace(createFace2(D, C, G, H, 3));
    group->addFace(createFace2(H, G, F, E, 5));

    this->_mesh->addGroup(group);

    this->_mesh->prepare();
}
