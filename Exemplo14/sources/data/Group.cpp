#include "../../headers/data/Group.h"

Group::Group(string name) {
    this->name = name;
}

Group::~Group() {
    this->faces.clear();
    this->faces.shrink_to_fit();

    glDeleteVertexArrays(1, &vao);
    for (auto& vbo : this->vbos) {
        glDeleteBuffers(1, &vbo);
    }

    this->vbos.clear();
    this->vbos.shrink_to_fit();
}

int Group::numVertices() {
    int sum = 0;
    for (auto& face : faces) {
        sum += face->getVertices().size();
    }
    return sum;
}

void Group::bindVAO() {
    if (this->vao == NULL) {
        glGenVertexArrays(1, &vao);
    }
    glBindVertexArray(vao);
}


void Group::bindBuffer(const vector<float>& data, const int vecSize) {
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data.front(), GL_STATIC_DRAW);

    glVertexAttribPointer(shaderLocation, vecSize, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(shaderLocation);

    shaderLocation++;
    this->addVBO(vbo);
}
