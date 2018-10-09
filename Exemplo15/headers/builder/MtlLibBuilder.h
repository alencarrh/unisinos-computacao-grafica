#ifndef MTL_LIB_BUILDER_H
#define MTL_LIB_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "MtlReader.h"

using namespace std;

static MtlReader* mtlFile;

class MtlLibBuilder {

public:
	static void process(std::stringstream& line);
};
#endif