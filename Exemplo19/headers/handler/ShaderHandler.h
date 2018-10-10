#ifndef SHADER_H
#define SHADER_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

class ShaderHandler {

public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    ShaderHandler(const GLchar* vertexPath, const GLchar* fragmentPath);

    // use/activate the shader
    void use();

    // utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMatrix4fv(const std::string& name, float matrix[]) const;
    void setMatrix4fv(const std::string& name, glm::mat4& matrix) const;
    void setVec3(const std::string& name, glm::vec3* vec) const;


private:
    static void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
