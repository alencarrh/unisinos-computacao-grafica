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
#include "../builder/MtlLibBuilder.h"

typedef void (*_function)(stringstream&);

using namespace std;

class MeshBuilder {

private:
    Mesh* mesh;
    map<string, _function> functions;

public:
    MeshBuilder();
    ~MeshBuilder();

    _function* function(string command);
    void processLine(string command, stringstream& line);
    Mesh* build();

};


#endif
