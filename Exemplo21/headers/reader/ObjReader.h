#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../data/Mesh.h"

using namespace std;

class ObjReader {

private:
    // MeshBuilder* meshBuilder;
    // MtlReader* mtlReader;

public:
    ObjReader();
    ~ObjReader();
    Mesh* read(string filename);

};
#endif
