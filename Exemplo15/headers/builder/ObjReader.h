#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../../headers/data/Mesh.h"
#include "../../headers/builder/MeshBuilder.h"

using namespace std;

class ObjReader {

private:
	MeshBuilder* meshBuilder;

public:

	Mesh* read(string filename);
};
#endif

