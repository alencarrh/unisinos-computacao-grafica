#include "../../headers/builder/MaterialMediator.h"

MaterialMediator::MaterialMediator(MaterialHandler* mesh) {}
MaterialMediator::~MaterialMediator() {}
void MaterialMediator::callbackKAmbient(glm::vec3* ka) {}
void MaterialMediator::callbackKDiffusse(glm::vec3* kd) {}
void MaterialMediator::callbackKSpecular(glm::vec3* ks) {}
void MaterialMediator::callbackNShinness(float ns) {}
