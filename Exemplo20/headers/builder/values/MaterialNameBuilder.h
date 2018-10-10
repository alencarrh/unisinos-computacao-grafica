#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

static string name;

class MaterialNameBuilder {

public:
    static void process(std::stringstream& line);
    static string build();
};
#endif
