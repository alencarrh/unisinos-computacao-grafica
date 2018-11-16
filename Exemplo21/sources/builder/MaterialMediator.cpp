#include "../../headers/builder/MaterialMediator.h"

MaterialMediator::MaterialMediator(MaterialHandler* mesh) {
    this->materialHandler = new MaterialHandler();
}

MaterialMediator::~MaterialMediator() {}

void MaterialMediator::callbackKAmbient(glm::vec3* ka) {
    this->currentMaterial->setAmbienteProperty(ka);
}

void MaterialMediator::callbackKDiffuse(glm::vec3* kd) {
    this->currentMaterial->setDiffuseProperty(kd);
}

void MaterialMediator::callbackKSpecular(glm::vec3* ks) {
    this->currentMaterial->setSpecularProperty(ks);
}

void MaterialMediator::callbackNShinness(float ns) {
    this->currentMaterial->setShininess(ns);
}

void MaterialMediator::callbackNewMaterial(string name) {
    if (this->currentMaterial) {
        this->materialHandler->addMaterial(this->currentMaterial);
    }
    this->currentMaterial = new Material(name);
}
