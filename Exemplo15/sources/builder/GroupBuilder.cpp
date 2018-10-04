#include "../../headers/builder/GroupBuilder.h"

void GroupBuilder::process(std::stringstream& line) {
    string name;
    line >> name;

    if (isFirstGroup()) {
        this->_currentGroup->setName(name);
        return;
    }

    this->groups.push_back(this->_currentGroup);
    this->_currentGroup = new Group(name);
}
