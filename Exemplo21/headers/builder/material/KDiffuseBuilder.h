#ifndef KDIFFUSE_BUILDER_H
#define KDIFFUSE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class KDiffuseBuilder : public Builder {

private:
    MaterialMediator* mediator;
public:
    KDiffuseBuilder(MaterialMediator* mediator);
    ~KDiffuseBuilder();

    void process(stringstream& line) override;
};
#endif
