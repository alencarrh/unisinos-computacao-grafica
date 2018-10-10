#include "../../headers/builder/MeshBuilder.h"

MeshBuilder::MeshBuilder() {
    functions.insert(make_pair("v", VerticeBuilder::process));
    functions.insert(make_pair("vn", NormalBuilder::process));
    functions.insert(make_pair("vt", TextureBuilder::process));
    functions.insert(make_pair("g", GroupBuilder::process));
    functions.insert(make_pair("mtllib", MtlLibBuilder::process));
}

MeshBuilder::~MeshBuilder() {}


_function* MeshBuilder::function(string command) {
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
    }
}

Mesh* MeshBuilder::build() {
    // cria a mesh e retorna
    this->mesh->setVertices(VerticeBuilder::build());
    mesh->setGroups(GroupBuilder::build());

    return this->mesh;
}
