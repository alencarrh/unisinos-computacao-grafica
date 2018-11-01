#include "../../headers/builder/MeshMediator.h"

MeshMediator::MeshMediator(Mesh* mesh) {
    this->mesh = mesh;
}

MeshMediator::~MeshMediator() {}
void MeshMediator::callbackFace(Face* face) {}
void MeshMediator::callbackGroup(string name) {}
void MeshMediator::callbackMaterialFile(string material) {}
void MeshMediator::callbackMaterialName(string name) {}
void MeshMediator::callbackNormal(glm::vec3* normais) {}
void MeshMediator::callbackTexture(glm::vec2* texture) {}
void MeshMediator::callbackVertice(glm::vec3* vertice) {}
