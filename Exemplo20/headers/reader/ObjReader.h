#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "MtlReader.h"
#include "../data/Mesh.h"
#include "../builder/data/MeshBuilder.h""

using namespace std;

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
