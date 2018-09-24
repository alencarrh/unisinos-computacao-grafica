#include "../../headers/data/Mesh.h"

Mesh::Mesh(string name) {
    this->name = name;
}

Mesh::~Mesh() {
    this->groups.clear();
    this->groups.shrink_to_fit();

    this->normais.clear();
    this->normais.shrink_to_fit();

    this->vertices.clear();
    this->vertices.shrink_to_fit();

    this->normais.clear();
    this->normais.shrink_to_fit();
}

glm::vec3* Mesh::vertice(int id) {
    return this->vertices[id];
}

glm::vec3* Mesh::normal(int id) {
    return this->normais[id];
}

glm::vec2* Mesh::texture(int id) {
    return this->textures[id];
}

void Mesh::setName(string name) {
    this->name = name;
}

void Mesh::setMaterial(string material) {
    this->material = material;
}

int Mesh::addGroup(Group* group) {
    this->groups.push_back(group);
    return this->groups.size() - 1;
}

int Mesh::addVertice(glm::vec3* vertice) {
    this->vertices.push_back(vertice);
    return this->vertices.size() - 1;
}

int Mesh::addNormal(glm::vec3* normal) {
    this->normais.push_back(normal);
    return this->normais.size() - 1;
}

int Mesh::addTexture(glm::vec2* texture) {
    this->textures.push_back(texture);
    return this->textures.size() - 1;
}

void Mesh::prepare() {
    for (Group* group : this->getGroups()) {
        vector<float> vertices;
        vector<float> normais;
        //TODO texturas
        for (Face* face : group->getFaces()) {

            for (int verticeID : face->getVertices()) {
                glm::vec3* vertice = this->vertice(verticeID);
                vertices.push_back(vertice->x);
                vertices.push_back(vertice->y);
                vertices.push_back(vertice->z);
            }

            for (int normalID : face->getNormais()) {
                glm::vec3* normal = this->normal(normalID);
                vertices.push_back(normal->x);
                vertices.push_back(normal->y);
                vertices.push_back(normal->z);
            }
        }

        group->bindVAO();
        if (!vertices.empty()) {
            group->bindBuffer(vertices);
        }
        if (!normais.empty()) {
            group->bindBuffer(normais);
        }
    }
}
