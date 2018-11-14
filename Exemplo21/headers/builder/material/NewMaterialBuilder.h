#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class NewMaterialBuilder : public Builder {
private:
    MaterialMediator* mediator;

public:
    NewMaterialBuilder(MaterialMediator* mediator);
    ~NewMaterialBuilder();
    void process(stringstream& line) override;
};

#endif
