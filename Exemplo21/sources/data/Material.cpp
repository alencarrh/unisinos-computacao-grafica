#include "../../headers/data/Material.h"


Material::Material(std::string name) {
    this->name = name;
}

Material::~Material() {}

void Material::setAmbienteProperty(glm::vec3* ambient) {
    this->ambient = ambient;
}

void Material::setDiffuseProperty(glm::vec3* diffuse) {
    this->diffuse = diffuse;
}

void Material::setSpecularProperty(glm::vec3* specular) {
    this->specular = specular;
}

void Material::setShininess(float shininess) {
    this->shininess = shininess;
}

void Material::setTextureName(std::string textureName) {
    this->textureName = textureName;
}

std::string Material::getName() {
    return this->name;
}

glm::vec3* Material::getAmbienteProperty() {
    return this->ambient;
}

glm::vec3* Material::getDiffuseProperty() {
    return this->diffuse;
}

glm::vec3* Material::getSpecularProperty() {
    return this->specular;
}

float Material::getShininess() {
    return this->shininess;
}

std::string Material::getTextureName() {
    return this->textureName;
}
