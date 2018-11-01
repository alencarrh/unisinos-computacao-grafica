#ifndef MATERIAL_FILE_BUILDER_H
#define MATERIAL_FILE_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class MaterialFileBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    MaterialFileBuilder(MeshMediator* mediator);
    ~MaterialFileBuilder();
    void process(stringstream& line) override;
};

#endif
