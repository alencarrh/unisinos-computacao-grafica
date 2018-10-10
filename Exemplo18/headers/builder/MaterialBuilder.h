#ifndef MATERIAL_BUILDER_H
#define MATERIAL_BUILDER_H

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

typedef void (*_function)(stringstream&);

using namespace std;

class MaterialBuilder {

private:
    map<string, _function> functions;

public:
    MaterialBuilder();
    ~MaterialBuilder();

    _function* function(string command);
    void processLine(string command, stringstream& line);
    //Mesh* build();

};

#endif
