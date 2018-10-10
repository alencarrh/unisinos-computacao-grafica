#ifndef OBJECT_H
#define OBJECT_H

#include "../actions/Drawable.h"
#include "../../headers/reader/ObjReader.h"

class Object : public Drawable {
private:
    Mesh* _mesh;
    ObjReader* objReader;
    string objFile;
	glm::vec3* _position;

public:
	Object();
	Object(string objFile, glm::vec3* postion);
    ~Object() override;
    void prepare() override;
    
    glm::vec3* position() override {
		return this->_position;
    }

    Mesh* mesh() override {
        return this->_mesh;
    }
};

#endif
