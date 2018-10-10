#include "../../../headers/builder/data/MeshBuilder.h"

MeshBuilder::MeshBuilder() {
    functions.insert(make_pair("v", VerticeBuilder::process));
    functions.insert(make_pair("vn", NormalBuilder::process));
    functions.insert(make_pair("vt", TextureBuilder::process));
    functions.insert(make_pair("g", GroupBuilder::process));
    functions.insert(make_pair("mtllib", MaterialNameBuilder::process));

    this->mesh = new Mesh();
}

MeshBuilder::~MeshBuilder() {}

_function* MeshBuilder::function(string command) {

    if (functions.find(command) == functions.end()) {
        return NULL;
    }

    _function* _func = &functions[command];

    if (_func) {
        return _func;
    }

    return NULL;
}

void MeshBuilder::processLine(string command, stringstream& line) {
    _function* _func = function(command);

    if (_func != NULL) {
        (*_func)(line);
        return;
    }

    if (command == "f") {
        FaceBuilder::process(GroupBuilder::currentGroup(), line);
		return;
    }
    if (command == "usemtl") {
        string id_material;
        line >> id_material;
        GroupBuilder::currentGroup()->setMaterialName(id_material);
		return;
    }
}

Mesh* MeshBuilder::build() {
    this->mesh->setVertices(VerticeBuilder::build());
    this->mesh->setNormais(NormalBuilder::build());
    this->mesh->setTextures(TextureBuilder::build());
    this->mesh->setGroups(GroupBuilder::build());
    this->mesh->setMaterialsFile(MaterialNameBuilder::build());
    return this->mesh;
}
