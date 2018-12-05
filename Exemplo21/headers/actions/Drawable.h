#ifndef DRAWABLE_H
#define DRAWABLE_H
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define FRENTE 0
#define TRAS 1
#include "../data/Mesh.h"

class Drawable {

public:
    Drawable() {}
    virtual ~Drawable() {};
    virtual void prepare() = 0;
    virtual Mesh* mesh() = 0;
    virtual glm::vec3* position() = 0;
	virtual glm::vec3* next_position() = 0;
	virtual void action(int action) = 0;
	virtual bool should_rotate() = 0;

};

#endif
