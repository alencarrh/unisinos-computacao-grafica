#include "../../headers/builder/MeshMediator.h"

MeshMediator::MeshMediator(Mesh* mesh) {
	this->mesh = mesh;
}
MeshMediator::~MeshMediator() {}
void MeshMediator::callbackFace(Face* face) {}
void MeshMediator::callbackGroup(string name) {}
void MeshMediator::callbackMaterial(Material* material) {}
void MeshMediator::callbackKAmbiente(glm::vec3* ka) {}
void MeshMediator::callbackKDiffuse(glm::vec3* kd) {}
void MeshMediator::callbackKSpecular(glm::vec3* ks) {}
void MeshMediator::callbackNShininness(float ns) {}
void MeshMediator::callbackMaterialName(string name) {}
void MeshMediator::callbackNormal(glm::vec3* normais) {}
void MeshMediator::callbackTexture(glm::vec2* texture) {}
void MeshMediator::callbackVertice(glm::vec3* vertice) {}
