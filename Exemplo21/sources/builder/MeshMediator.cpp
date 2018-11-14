#include "../../headers/builder/MeshMediator.h"

MeshMediator::MeshMediator(Mesh* mesh) {
    this->mesh = mesh;
}

MeshMediator::~MeshMediator() {}

void MeshMediator::callbackFace(Face* face) {
    this->currentGroup->addFace(face);
}

void MeshMediator::callbackGroup(string name) {
    if (this->firstGroup) {
        this->currentGroup->setName(name);
        this->firstGroup = false;
        return;
    }

    this->mesh->addGroup(this->currentGroup);
    this->currentGroup = new Group(name);
}

void MeshMediator::callbackMaterialFile(string materialFile) {
    this->mesh->setMaterialsFile(materialFile);
}

void MeshMediator::callbackMaterialName(string name) {
    this->currentGroup->setMaterialName(name);
}

void MeshMediator::callbackNormal(glm::vec3* normal) {
    this->mesh->addNormal(normal);
}

void MeshMediator::callbackTexture(glm::vec2* texture) {
    this->mesh->addTexture(texture);
}

void MeshMediator::callbackVertice(glm::vec3* vertice) {
    this->mesh->addVertice(vertice);
}
