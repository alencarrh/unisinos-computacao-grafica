#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class NewMaterialNameBuilder : public Builder {
private:
    MaterialMediator* mediator;

public:
    NewMaterialNameBuilder(MaterialMediator* mediator);
    ~NewMaterialNameBuilder();
    void process(stringstream& line) override;
};

#endif
