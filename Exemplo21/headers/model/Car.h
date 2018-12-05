#ifndef CAR_H
#define CAR_H

#include "../actions/Drawable.h"
#include "../../headers/reader/ObjReader.h"

class Car : public Drawable {
    Mesh* _mesh;
    ObjReader* objReader;
    string objFile;
    string route;
    vector<glm::vec3*> positions;
    int current_position;
	int lastAction;

public:
    Car(string objFile, string route);
    ~Car() override;
    void prepare() override;
    Mesh* mesh() override;
    glm::vec3* position() override;
    glm::vec3* next_position() override;
    void action(int action) override;

    bool should_rotate() override {
		return true;
    }
};


#endif
