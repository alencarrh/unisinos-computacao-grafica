#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include "../../data/Mesh.h"
#include "FaceBuilder.h"
#include "GroupBuilder.h"
#include "../values/VerticeBuilder.h"
#include "../values/NormalBuilder.h"
#include "../values/TextureBuilder.h"
#include "../values/MaterialNameBuilder.h"

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
