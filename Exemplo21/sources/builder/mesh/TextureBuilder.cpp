#include "../../../headers/builder/mesh/TextureBuilder.h"


TextureBuilder::TextureBuilder(MeshMediator* mediator) {
    this->mediator = mediator;
}

TextureBuilder::~TextureBuilder() {}

void TextureBuilder::process(stringstream& line) {
    float x, y;
    line >> x >> y;

    this->mediator->callbackTexture(new glm::vec2(x, y));
}
