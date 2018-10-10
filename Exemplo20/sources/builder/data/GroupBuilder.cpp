#include "../../headers/builder/data/GroupBuilder.h"

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

vector<Group*>& GroupBuilder::build() {
    groups.push_back(_currentGroup);
    vector<Group*> temp = groups;

    //Como esta classe é estática, após fazer o build deve-se fazer um clean dos valores
    // para quando for utilizada novamente não ter lixo do processo anterior
    groups.clear();
    groups.shrink_to_fit();

    return temp;
}

Group* GroupBuilder::currentGroup() {
    return _currentGroup;
}

bool GroupBuilder::isFirstGroup() {
    return groups.empty();
}
