#ifndef TEXTURE_BUILDER_H
#define TEXTURE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

static vector<glm::vec2*> textures;

class TextureBuilder {

public:
    static void process(std::stringstream& line);
    static vector<glm::vec2*>& build();

};
#endif
