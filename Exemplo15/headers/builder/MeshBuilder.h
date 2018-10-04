#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include "../data/Mesh.h"
#include "../builder/FaceBuilder.h"
#include "../builder/GroupBuilder.h"
#include "../builder/VerticeBuilder.h"
#include "../builder/NormalBuilder.h"
#include "../builder/TextureBuilder.h"
#include "../builder/MaterialBuilder.h"

typedef void (*_function)(stringstream&);

using namespace std;

class MeshBuilder {

private:
    Mesh* mesh;

    FaceBuilder* faceBuilder;
    GroupBuilder* groupBuilder;
    VerticeBuilder* verticeBuilder;
    NormalBuilder* normalBuilder;
    TextureBuilder* textureBuilder;
    MaterialBuilder* materialBuilder;

    map<string, _function> functions;

public:
    MeshBuilder();
    ~MeshBuilder();

    _function* function(string command);
    void processLine(string command, stringstream& line);
    Mesh* build();

};


#endif
