#ifndef FACE_BUILDER_H
#define FACE_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../../data/Group.h"

class FaceBuilder {
public:
    FaceBuilder();
    ~FaceBuilder();

    static void process(Group* group, std::stringstream& line);
};

#endif
