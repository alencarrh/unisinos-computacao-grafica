#ifndef GROUP_H
#define GROUP_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
#include <iostream>
#include "Face.h"
#include "../utils/stb_image.h"


using namespace std;

class Group {

private:
    string name;
    string material;
    vector<Face*> faces;
    vector<GLuint> vbos;
    GLuint vao = NULL;
    GLuint texture = NULL;
    int shaderLocation = 0;

public:
    Group(string name);
    ~Group();

    int numVertices();

    void bindVAO();
    void bindTexture();
    void bindBuffer(const vector<float>& data, const int vecSize = 3);

    void setTexture(string filename);
    void setName(string newName);
    void setMaterialName(string material);

    void addFace(Face* face);
    void addVBO(GLuint vbo);

    vector<Face*>& getFaces();
    string getName();
    string getMaterialName();

};

#endif
