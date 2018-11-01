#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "../Builder.h"
#include "../MeshMediator.h"
#include "../../data/Mesh.h"
#include "FaceBuilder.h"
#include "GroupBuilder.h"
#include "./MaterialNameBuilder.h"
#include "./MaterialFileBuilder.h"
#include "./NormalBuilder.h"
#include "./TextureBuilder.h"
#include "./VerticeBuilder.h"

using namespace std;

class MeshBuilder {

private:
    Mesh* mesh;
    MeshMediator* mediator;
    map<string, Builder*> functions;

    //builders
    FaceBuilder* faceBuilder;
    GroupBuilder* groupBuilder;
    MaterialNameBuilder* materialNameBuilder;
    MaterialFileBuilder* materialFileBuilder;
    NormalBuilder* normalBuilder;
    TextureBuilder* textureBuilder;
    VerticeBuilder* verticeBuilder;

    Builder* function(string command);

public:
    MeshBuilder();
    ~MeshBuilder();

    void processLine(string command, stringstream& line);
    Mesh* build();

};
#endif
