#include "../../headers/builder/TextureBuilder.h"

void TextureBuilder::process(stringstream& line) {
    float x, y;
    line >> x >> y;
    this->textures.push_back(new glm::vec2(x, y));
}

vector<glm::vec2*>& TextureBuilder::build() {
    return this->textures;
}
