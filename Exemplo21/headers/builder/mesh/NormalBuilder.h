#ifndef NORMAL_BUILDER_H
#define NORMAL_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class NormalBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    NormalBuilder(MeshMediator* mediator);
    ~NormalBuilder();
    void process(stringstream& line) override;
};

#endif
