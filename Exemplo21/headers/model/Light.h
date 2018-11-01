#ifndef LIGHT_H
#define LIGHT_H
#include <GLM/detail/type_vec3.hpp>


class Light {
public:

    glm::vec3* color;
    glm::vec3* position;
    glm::vec3* ambient;
    glm::vec3* diffuse;
    glm::vec3* specular;
    bool on = true;

    Light();
    ~Light();

};


#endif
