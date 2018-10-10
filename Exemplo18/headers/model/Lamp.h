#ifndef LAMP_H
#define LAMP_H

#include "../actions/Drawable.h"

class Lamp : public Drawable {
private:
	Mesh* _mesh;

public:
	Lamp();
	~Lamp() override;
	void prepare() override;

	Mesh* mesh() override {
		return this->_mesh;
	}
};

#endif
