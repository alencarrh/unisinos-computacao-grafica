#ifndef NSHINNESS_BUILDER_H
#define NSHINNESS_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <GLM/glm.hpp>
#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class NShininessBuilder : public Builder {

private:
    MaterialMediator* mediator;

public:
    NShininessBuilder(MaterialMediator* mediator);
    ~NShininessBuilder();

    void process(stringstream& line) override;
};

#endif
