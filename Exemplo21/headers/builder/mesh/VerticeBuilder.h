#ifndef VERTICE_BUILDER_H
#define VERTICE_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class VerticeBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    VerticeBuilder(MeshMediator* mediator);
    ~VerticeBuilder();
    void process(stringstream& line) override;
};
#endif
