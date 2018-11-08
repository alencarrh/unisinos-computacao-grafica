#ifndef MATERIAL_NAME_BUILDER_H
#define MATERIAL_NAME_BUILDER_H

#include "../MaterialMediator.h"
#include "../Builder.h"

using namespace std;

class TextureNameBuilder : public Builder {
private:
    MaterialMediator* mediator;

public:
    TextureNameBuilder(MaterialMediator* mediator);
    ~TextureNameBuilder();
    void process(stringstream& line) override;
};

#endif
