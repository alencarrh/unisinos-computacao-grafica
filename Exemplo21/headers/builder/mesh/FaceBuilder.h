#ifndef FACE_BUILDER_H
#define FACE_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class FaceBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    FaceBuilder(MeshMediator* mediator);
    ~FaceBuilder();

    void process(stringstream& line) override;
};

#endif
