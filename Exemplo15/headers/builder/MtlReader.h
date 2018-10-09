#ifndef MTL_READER_H
#define MTL_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../../headers/data/Mesh.h"
#include "../../headers/builder/MaterialBuilder.h"

using namespace std;

class MtlReader{

private:
	MaterialBuilder * materialBuilder;

public:
	Mesh* read(string filename);
};
#endif