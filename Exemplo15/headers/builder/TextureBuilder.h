#ifndef TEXTURE_BUILDER_H
#define TEXTURE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

class TextureBuilder {

private:
	vector<glm::vec2*> textures;

public:
    void process(std::stringstream& line);
	vector<glm::vec2*>& build();

};
#endif