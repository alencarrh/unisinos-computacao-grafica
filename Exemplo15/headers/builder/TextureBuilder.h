#pragma once
#include <sstream>
#include <string>

class TextureBuilder {
public:
    TextureBuilder();
    ~TextureBuilder();

    void process(std::stringstream& s);
};
