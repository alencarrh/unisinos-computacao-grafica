#include "../../headers/builder/VerticeBuilder.h"

#include <iostream>
#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>

using namespace std;

class VerticeBuilder {

    vector<glm::vec3> vertices;

    void process(stringstream& line) {
        float x, y, z;
        line >> x >> y >> z;
        vertices.push_back(glm::vec3(x, y, z));
    }

    vector<glm::vec3>& build() {
        return this->vertices;
    }


};
