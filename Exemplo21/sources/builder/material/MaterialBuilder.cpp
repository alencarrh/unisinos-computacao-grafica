#include "../../headers/builder/material/MaterialBuilder.h"

Builder* MaterialBuilder::function(string command) {
    if (functions.find(command) == functions.end()) {
        return nullptr;
    }

    Builder* builder = functions[command];

    if (builder) {
        return builder;
    }

    return nullptr;
}

MaterialBuilder::MaterialBuilder() {
    this->materialHandler = new MaterialHandler();
    this->mediator = new MaterialMediator(materialHandler);

    this->kAmbientBuilder = new KAmbientBuilder(mediator);
    this->kDiffuseBuilder = new KDiffuseBuilder(mediator);
    this->kSpecularBuilder = new KSpecularBuilder(mediator);
    this->nShininessBuilder = new NShininessBuilder(mediator);


    functions.insert(make_pair("Ka", kAmbientBuilder));
    functions.insert(make_pair("Kd", kDiffuseBuilder));
    functions.insert(make_pair("Ks", kSpecularBuilder));
    functions.insert(make_pair("Ns", nShininessBuilder));
    functions.insert(make_pair("newmtl", materialNameBuilder));


}

MaterialBuilder::~MaterialBuilder() {}

void MaterialBuilder::processLine(string command, stringstream& line) {
    Builder* builder = function(command);

    if (builder != nullptr) {
        builder->process(line);
    }

}

MaterialHandler* MaterialBuilder::build() {
    return this->

}
