#include "../../headers/handler/MaterialHandler.h"


MaterialHandler::MaterialHandler() {
    defaultMaterial = new Material("default");

    // TODO pass the default values to one config file
    defaultMaterial->setAmbienteProperty(new glm::vec3(1.0f));
    defaultMaterial->setDiffuseProperty(new glm::vec3(1.0f));
    defaultMaterial->setSpecularProperty(new glm::vec3(1.0f));
    defaultMaterial->setShininess(128.0f);
    defaultMaterial->setTextureName("./files/textures/default.jpg");

    this->materials.insert(make_pair("default", defaultMaterial));
}

MaterialHandler::~MaterialHandler() {}

void MaterialHandler::addMaterial(Material* material) {
    this->materials.insert(make_pair(material->getName(), material));
}


Material* MaterialHandler::getMaterial(string materialName) {
    if (materials.find(materialName) == materials.end()) {
        return defaultMaterial;
    }
    return this->materials[materialName];
}
