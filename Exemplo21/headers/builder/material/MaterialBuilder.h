#ifndef MATERIAL_BUILDER_H
#define MATERIAL_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include "../MaterialMediator.h"
#include "../Builder.h"
#include "NShininessBuilder.h"
#include "KAmbientBuilder.h"
#include "KDiffuseBuilder.h"
#include "KSpecularBuilder.h"
#include "NewMaterialBuilder.h"

using namespace std;

class MaterialBuilder {

private:
    MaterialHandler* materialHandler;
    MaterialMediator* mediator;
    map<string, Builder*> functions;

    //builders
    KAmbientBuilder* kAmbientBuilder;
    KDiffuseBuilder* kDiffuseBuilder;
    KSpecularBuilder* kSpecularBuilder;
    NShininessBuilder* nShininessBuilder;
    NewMaterialBuilder* newMaterialBuilder;

    Builder* function(string command);

public:
    MaterialBuilder();
    ~MaterialBuilder();

    void processLine(string command, stringstream& line);
    MaterialHandler* build();

};
#endif
