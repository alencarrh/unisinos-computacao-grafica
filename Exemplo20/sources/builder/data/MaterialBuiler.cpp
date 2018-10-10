#include "../../../headers/builder/data/MaterialBuilder.h"

MaterialBuilder::MaterialBuilder() {
    functions.insert(make_pair("newmtl", MaterialNameBuilder::process));
    functions.insert(make_pair("Ka", KAmbientBuilder::process));
    functions.insert(make_pair("Kd", KDiffuseBuilder::process));
    functions.insert(make_pair("Ks", KSpecularBuilder::process));
    functions.insert(make_pair("Ns", NShininessBuilder::process));

}

MaterialBuilder::~MaterialBuilder() {}


_function* MaterialBuilder::function(string command) {
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

        Material* material = new Material(MaterialNameBuilder::build());
        material->setTextureName(texture_path_name);
        material->setAmbienteProperty(KAmbientBuilder::build());
        material->setDiffuseProperty(KDiffuseBuilder::build());
        material->setSpecularProperty(KSpecularBuilder::build());
        material->setShininess(NShininessBuilder::build());

        materialHandler->addMaterial(material);
		return;
    }


}

MaterialHandler* MaterialBuilder::build() { }
