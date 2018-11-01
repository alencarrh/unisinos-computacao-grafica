#include "../../../headers/builder/data/MeshBuilder.h"

_function* MeshBuilder::function(string command) {
    if (functions.find(command) == functions.end()) {
        return nullptr;
    }

    _function* _func = &functions[command];

    if (_func) {
        return _func;
    }

    return nullptr;
}

MeshBuilder::MeshBuilder() {
    this->mesh = new Mesh();
    this->mediator = new MeshMediator(mesh);

    this->faceBuilder = new FaceBuilder(mediator);
    this->groupBuilder = new GroupBuilder(mediator);
    this->materialNameBuilder = new MaterialNameBuilder(mediator);
    this->materialFileBuilder = new MaterialFileBuilder(mediator);
    this->verticeBuilder = new VerticeBuilder(mediator);
    this->normalBuilder = new NormalBuilder(mediator);
    this->textureBuilder = new TextureBuilder(mediator);


    functions.insert(make_pair("v", verticeBuilder->process));
    functions.insert(make_pair("vn", normalBuilder->process));
    functions.insert(make_pair("vt", textureBuilder->process));
    functions.insert(make_pair("g", groupBuilder->process));
    functions.insert(make_pair("f", faceBuilder->process));
    functions.insert(make_pair("mtllib", materialFileBuilder->process));
    functions.insert(make_pair("usemtl", materialNameBuilder->process));

}

MeshBuilder::~MeshBuilder() {}


void MeshBuilder::processLine(string command, stringstream& line) {
	_function* _func = function(command);

	if (_func != nullptr) {
		(*_func)(line);
		return;
	}

}

Mesh* MeshBuilder::build() {
    return this->mesh;
}
