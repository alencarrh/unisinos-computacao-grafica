#ifndef MATERIAL_H
#define MATERIAL_H

#include <GLM/detail/type_vec3.hpp>
#include <string>

class Material {

private:
    std::string name;
    glm::vec3* ambient;
    glm::vec3* diffuse;
    glm::vec3* specular;
    float shininess;
    std::string textureName;

public:
    Material(std::string name);
    ~Material();

    void setShininess(float shininess);
    void setTextureName(std::string textureName);
    void setAmbienteProperty(glm::vec3* ambient);
    void setDiffuseProperty(glm::vec3* diffuse);
    void setSpecularProperty(glm::vec3* specular);

    std::string getName();
    float getShininess();
    std::string getTextureName();
    glm::vec3* getAmbienteProperty();
    glm::vec3* getDiffuseProperty();
    glm::vec3* getSpecularProperty();


};

#endif
