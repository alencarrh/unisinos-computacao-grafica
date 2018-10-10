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

    void setAmbienteProperty(glm::vec3* ambient) {
        this->ambient = ambient;
    }

    void setDiffuseProperty(glm::vec3* diffuse) {
        this->diffuse = diffuse;
    }

    void setSpecularProperty(glm::vec3* specular) {
        this->specular = specular;
    }

    void setShininess(float shininess) {
        this->shininess = shininess;
    }

    void setTextureName(std::string textureName) {
        this->textureName = textureName;
    }

    std::string getName() {
        return this->name;
    }

    glm::vec3* getAmbienteProperty() {
        return this->ambient;
    }

    glm::vec3* getDiffuseProperty() {
        return this->diffuse;
    }

    glm::vec3* getSpecularProperty() {
        return this->specular;
    }

    float getShininess() {
        return this->shininess;
    }

    std::string getTextureName() {
        return this->textureName;
    }

};

#endif
