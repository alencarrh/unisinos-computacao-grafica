#ifndef GROUP_BUILDER_H
#define GROUP_BUILDER_H

#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../data/Group.h"

using namespace std;

class GroupBuilder {

private:
    vector<Group*> groups;
    Group* _currentGroup = new Group("default");

public:
    void process(std::stringstream& line);

    vector<Group*>& build() {
        this->groups.push_back(_currentGroup);
        return this->groups;
    }

    Group* currentGroup() {
        return _currentGroup;
    }

    bool isFirstGroup() {
        return this->groups.empty();
    }

};
#endif
