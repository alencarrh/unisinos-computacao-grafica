#ifndef NSHININESS_BUILDER_H
#define NSHININESS_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;
static float ns;

class NShininessBuilder {

public:
    static void process(stringstream& line);
    static float build();

};

#endif
