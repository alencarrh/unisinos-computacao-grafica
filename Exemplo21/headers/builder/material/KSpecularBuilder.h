#ifndef KSPECULAR_BUILDER_H
#define KSPECULAR_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class KSpecularBuilder : public Builder {

private:
    MaterialMediator* mediator;
public:
    KSpecularBuilder(MaterialMediator* mediator);
    ~KSpecularBuilder();

    void process(stringstream& line) override;
};
#endif
