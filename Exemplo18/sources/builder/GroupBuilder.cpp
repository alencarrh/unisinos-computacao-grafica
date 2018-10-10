#include "../../headers/builder/GroupBuilder.h"

void GroupBuilder::process(std::stringstream& line) {
    string name;
    line >> name;

    if (isFirstGroup()) {
        _currentGroup->setName(name);
        return;
    }

    groups.push_back(_currentGroup);
    _currentGroup = new Group(name);
}
