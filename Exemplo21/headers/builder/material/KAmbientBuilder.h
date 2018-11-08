#ifndef KAMBIENT_BUILDER_H
#define KAMBIENT_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class KAmbientBuilder : public Builder {

private:
    MaterialMediator* mediator;
public:
    KAmbientBuilder(MaterialMediator* mediator);
    ~KAmbientBuilder();

    void process(stringstream& line) override;
};
#endif
