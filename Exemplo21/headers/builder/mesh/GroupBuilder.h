#ifndef GROUP_BUILDER_H
#define GROUP_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class GroupBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    GroupBuilder(MeshMediator* mediator);
    ~GroupBuilder();
    void process(stringstream& line) override;
};

#endif
