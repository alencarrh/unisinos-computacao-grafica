#ifndef MATERIAL_BUILDER_H
#define MATERIAL_BUILDER_H

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../../handler/MaterialHandler.h"
#include "../values/MaterialNameBuilder.h"
#include "../light/KAmbientBuilder.h"
#include "../light/KDiffuseBuilder.h"
#include "../light/KSpecularBuilder.h"
#include "../light/NShininessBuilder.h"

using namespace std;

typedef void (*_function)(stringstream&);

using namespace std;

class MaterialBuilder {

private:
    MaterialHandler* materialHandler;
    map<string, _function> functions;

public:
    MaterialBuilder();
    ~MaterialBuilder();

    _function* function(string command);
    void processLine(string command, stringstream& line);
    MaterialHandler* build();

};

#endif
