#ifndef TEXTURE_BUILDER_H
#define TEXTURE_BUILDER_H

#include "../MeshMediator.h"
#include "../Builder.h"

using namespace std;

class TextureBuilder : public Builder {
private:
    MeshMediator* mediator;

public:
    TextureBuilder(MeshMediator* mediator);
    ~TextureBuilder();
    void process(stringstream& line) override;
};
#endif
