#ifndef MTL_READER_H
#define MTL_READER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../data/Mesh.h"
#include "../builder/data/MaterialBuilder.h"

using namespace std;

class MtlReader {

private:
    MaterialBuilder* materialBuilder;

public:
    MtlReader();
    ~MtlReader();

    MaterialHandler* read(string filename);
};
#endif
