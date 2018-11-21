#include "../../headers/builder/MaterialMediator.h"

MaterialMediator::MaterialMediator(MaterialHandler* handler) {
	this->materialHandler = handler;
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


void MaterialMediator::callbackTextureName(string name) {
	this->currentMaterial->setTextureName(name);
}

void MaterialMediator::callbackNewMaterial(string name) {
    this->currentMaterial = new Material(name);
    this->materialHandler->addMaterial(this->currentMaterial);
}
