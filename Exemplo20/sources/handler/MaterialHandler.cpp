#include "../../headers/handler/MaterialHandler.h"


MaterialHandler::MaterialHandler() {}
MaterialHandler::~MaterialHandler() {}

void MaterialHandler::addMaterial(Material* material) {
    this->materials.insert(make_pair(material->getName(), material));
}

Material* MaterialHandler::getMaterial(string materialName) {
    if (materials.find(materialName) == materials.end()) {
        return NULL;
    }
    return this->materials[materialName];
}
