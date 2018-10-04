#ifndef CUBE_H
#define CUBE_H

#include "../actions/Drawable.h"

class Cube : public Drawable {
private:
    Mesh* _mesh;

public:
    Cube();
    ~Cube() override;
    void prepare() override;

    Mesh* mesh() override {
        return this->_mesh;
    };


};

#endif
