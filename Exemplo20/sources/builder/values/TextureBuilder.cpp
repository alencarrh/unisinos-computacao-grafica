#include "../../../headers/builder/values/TextureBuilder.h"

void TextureBuilder::process(stringstream& line) {
    float x, y;
    line >> x >> y;
    textures.push_back(new glm::vec2(x, y));
}

vector<glm::vec2*>& TextureBuilder::build() {
    //TODO limpar lista aqui já que está classe está static
    return textures;
}
