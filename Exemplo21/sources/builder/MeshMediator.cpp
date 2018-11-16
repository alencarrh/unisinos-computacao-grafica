#include "../../headers/builder/MeshMediator.h"

MeshMediator::MeshMediator(Mesh* mesh) {
    this->mesh = mesh;
    this->groupNumber = 0;
    this->currentGroup = new Group("default123");
    this->mesh->addGroup(this->currentGroup);
}

MeshMediator::~MeshMediator() {}

void MeshMediator::callbackFace(Face* face) {
    this->currentGroup->addFace(face);
}

void MeshMediator::callbackGroup(string name) {
    this->groupNumber++;

    if (this->groupNumber == 1) {
        this->currentGroup->setName(name);
        return;
    }

    this->currentGroup = new Group(name);
	this->mesh->addGroup(this->currentGroup);
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
