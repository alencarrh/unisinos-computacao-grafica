#ifndef LAMP_H
#define LAMP_H

#include "../actions/Drawable.h"

class Lamp : public Drawable {
private:
    Mesh* _mesh;
    glm::vec3* _position;

public:
    Lamp();
    ~Lamp() override;
    void prepare() override;

    glm::vec3* position() override {
        return this->_position;
    }

    Mesh* mesh() override {
        return this->_mesh;
    }
};

#endif
