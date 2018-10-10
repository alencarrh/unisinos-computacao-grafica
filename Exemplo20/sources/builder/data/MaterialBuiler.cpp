#include "../../../headers/builder/data/MaterialBuilder.h"

MaterialBuilder::MaterialBuilder() {
    // functions.insert(make_pair("newmtl", MaterialNameBuilder::process));
    functions.insert(make_pair("Ka", KAmbientBuilder::process));
    functions.insert(make_pair("Kd", KDiffuseBuilder::process));
    functions.insert(make_pair("Ks", KSpecularBuilder::process));
    functions.insert(make_pair("Ns", NShininessBuilder::process));

    this->materialHandler = new MaterialHandler();

}

MaterialBuilder::~MaterialBuilder() {}


_function* MaterialBuilder::function(string command) {

    if (functions.find(command) == functions.end()) {
        return NULL;
    }

    _function* _func = &functions[command];

    if (_func) {
        return _func;
    }

    return NULL;
}

void MaterialBuilder::processLine(string command, stringstream& line) {
    _function* _func = function(command);

    if (_func != NULL) {
        (*_func)(line);
        return;
    }

    if (command == "map_Kd") {
        string texture_path_name;
        line >> texture_path_name;
        currentMaterial->setTextureName(texture_path_name);
        return;
    }

    if (command == "newmtl") {
        string nome_material;
        line >> nome_material;

        if (currentMaterial == NULL) {
            currentMaterial = new Material(nome_material);
            return;
        }

        currentMaterial->setAmbienteProperty(KAmbientBuilder::build());
        currentMaterial->setDiffuseProperty(KDiffuseBuilder::build());
        currentMaterial->setSpecularProperty(KSpecularBuilder::build());
        currentMaterial->setShininess(NShininessBuilder::build());
        materialHandler->addMaterial(currentMaterial);

        currentMaterial = NULL;
    }


}

MaterialHandler* MaterialBuilder::build() {
    if (currentMaterial != NULL) {
        currentMaterial->setAmbienteProperty(KAmbientBuilder::build());
        currentMaterial->setDiffuseProperty(KDiffuseBuilder::build());
        currentMaterial->setSpecularProperty(KSpecularBuilder::build());
        currentMaterial->setShininess(NShininessBuilder::build());
        materialHandler->addMaterial(currentMaterial);
    }
    return this->materialHandler;
}
