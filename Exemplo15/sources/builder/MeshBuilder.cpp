#include "../../headers/builder/MeshBuilder.h"

MeshBuilder::MeshBuilder() {
    functions.insert(make_pair("v", verticeBuilder->process));
    functions.insert(make_pair("vn", normalBuilder->process));
    functions.insert(make_pair("vt", textureBuilder->process));
    functions.insert(make_pair("g", groupBuilder->process));
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
        faceBuilder->process(groupBuilder->currentGroup(), line);
    }
}

Mesh* MeshBuilder::build() {
    // cria a mesh e retorna
    this->mesh->setVertices(verticeBuilder->build());
    mesh->setGroups(this->groupBuilder->build());

    return this->mesh;
}
