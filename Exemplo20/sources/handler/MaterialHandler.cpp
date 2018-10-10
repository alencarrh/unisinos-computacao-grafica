#include "../../headers/handler/MaterialHandler.h"


MaterialHandler::MaterialHandler() {
	defaultMaterial = new Material("Default");

	defaultMaterial->setAmbienteProperty(new glm::vec3(1.0f));
	defaultMaterial->setDiffuseProperty(new glm::vec3(1.0f));
	defaultMaterial->setSpecularProperty(new glm::vec3(1.0f));
	defaultMaterial->setShininess(128.0f);
	// default->setTextureName("./files/textures/container.jpg");

	this->materials.insert(make_pair("Default", defaultMaterial));
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
