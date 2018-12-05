#ifndef CAR_H
#define CAR_H

#include "../actions/Drawable.h"
#include "../../headers/reader/ObjReader.h"

class Car : public Drawable {
    Mesh* _mesh;
    ObjReader* objReader;
    string objFile;
    string curve_position;
    vector<glm::vec3*> positions;
    int current_position;

public:
    Car(string objFile, string curve_postions);
    ~Car() override;
    void prepare() override;
    Mesh* mesh() override;
    glm::vec3* position() override;
    void action(int action) override;
};


#endif
