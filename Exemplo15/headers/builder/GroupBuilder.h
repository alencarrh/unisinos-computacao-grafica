#ifndef GROUP_BUILDER_H
#define GROUP_BUILDER_H

#include <sstream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "../data/Group.h"

using namespace std;

static Group* _currentGroup = new Group("default");
static vector<Group*> groups;

class GroupBuilder {

public:
	static void process(std::stringstream& line);

	static vector<Group*>& build() {
        groups.push_back(_currentGroup);
        return groups;
    }

    static Group* currentGroup() {
        return _currentGroup;
    }

    static bool isFirstGroup() {
        return groups.empty();
    }

};
#endif
