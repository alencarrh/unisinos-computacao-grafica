#ifndef BUILDER_H
#define  BUILDER_H

#include <sstream>
using namespace std;
class Builder {

public:
    virtual void process(stringstream& line) = 0;

};

#endif
