#include "../../../headers/builder/mesh/MeshBuilder.h"

Builder* MeshBuilder::function(string command) {
    if (functions.find(command) == functions.end()) {
        return nullptr;
    }

    Builder* builder = functions[command];

    if (builder) {
        return builder;
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


    functions.insert(make_pair("v", verticeBuilder));
    functions.insert(make_pair("vn", normalBuilder));
    functions.insert(make_pair("vt", textureBuilder));
    functions.insert(make_pair("g", groupBuilder));
    functions.insert(make_pair("f", faceBuilder));
    functions.insert(make_pair("mtllib", materialFileBuilder));
    functions.insert(make_pair("usemtl", materialNameBuilder));

}

MeshBuilder::~MeshBuilder() {}


void MeshBuilder::processLine(string command, stringstream& line) {
    Builder* builder = function(command);

    if (builder != nullptr) {
        builder->process(line);
    }

}

Mesh* MeshBuilder::build() {
    return this->mesh;
}
