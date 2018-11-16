#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../data/Mesh.h"

class Drawable {

public:
    Drawable() {}
    virtual ~Drawable() {};
    virtual void prepare() = 0;
    virtual Mesh* mesh() = 0;
    virtual glm::vec3* position() = 0;
};

#endif
