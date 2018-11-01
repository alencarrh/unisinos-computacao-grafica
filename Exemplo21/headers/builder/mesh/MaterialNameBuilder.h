#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class MaterialNameBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    MaterialNameBuilder(MeshMediator* mediator);
    ~MaterialNameBuilder();
    void process(stringstream& line) override;
};

#endif
