#ifndef MESA_H
#define MESA_H

#include "../actions/Drawable.h"
#include "../../headers/reader/ObjReader.h"

class Mesa : public Drawable {
private:
    Mesh* _mesh;
    ObjReader* objReader;
    string objFile;

public:
    Mesa();
    Mesa(string objFile);
    ~Mesa() override;
    void prepare() override;

    Mesh* mesh() override {
        return this->_mesh;
    }
};

#endif
