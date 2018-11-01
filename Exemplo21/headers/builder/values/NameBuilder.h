#ifndef NAME_BUILDER_H
#define NAME_BUILDER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../MeshMediator.h"

using namespace std;

class NameBuilder {
private:
	MeshMediator* mediator;

public:
    NameBuilder(MeshMediator* mediator);
    ~NameBuilder();
    void process(std::stringstream& line);
};
#endif
