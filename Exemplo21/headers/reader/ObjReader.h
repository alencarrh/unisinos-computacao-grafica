#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../builder/mesh/MeshBuilder.h"
#include  "MtlReader.h"



using namespace std;

static map<string, Mesh*> meshes;

class ObjReader {

private:
    MeshBuilder* meshBuilder;
    MtlReader* mtlReader;

public:
    ObjReader();
    ~ObjReader();
    Mesh* read(string filename);

};
#endif
