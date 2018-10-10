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

void Mesh::setMaterialsFile(string materialsFile) {
    this->materialsFile = materialsFile;
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

void Mesh::setGroups(vector<Group*>& groups) {
    this->groups = groups;
}

void Mesh::setVertices(vector<glm::vec3*>& vertices) {
    this->vertices = vertices;
}

void Mesh::setNormais(vector<glm::vec3*>& normais) {
    this->normais = normais;
}

void Mesh::setTextures(vector<glm::vec2*>& textures) {
    this->textures = textures;
}

void Mesh::setMaterialsHandler(MaterialHandler* handler) {
    this->materialsHandler = handler;
}

Material* Mesh::getMaterial(string materialName) {
    return this->materialsHandler->getMaterial(materialName);
}

vector<Group*>& Mesh::getGroups() {
    return groups;
}

string Mesh::getMaterialsFile() {
    return this->materialsFile;
}

void Mesh::prepare() {

    glm::vec3* vertice;
    glm::vec3* normal;
    glm::vec2* texture;

    for (Group* group : this->getGroups()) {
        vector<float> vertices;
        vector<float> normais;
        vector<float> textures;
        for (Face* face : group->getFaces()) {

            //TODO the below code for vertices and normais are equal, and the only thing different for texture
            //     is that only it ignores Z coordinate. The goal is try to do only 1 method for this logic.

            for (int verticeID : face->getVertices()) {
                vertice = this->vertice(verticeID);
                vertices.push_back(vertice->x);
                vertices.push_back(vertice->y);
                vertices.push_back(vertice->z);
                // delete vertice;
            }

            for (int normalID : face->getNormais()) {
                normal = this->normal(normalID);
                normais.push_back(normal->x);
                normais.push_back(normal->y);
                normais.push_back(normal->z);
                // delete normal;
            }

            for (int textureID : face->getTextures()) {
                texture = this->texture(textureID);
                textures.push_back(texture->x);
                textures.push_back(texture->y);
                // delete texture;
            }
        }


        group->bindVAO();
        if (!vertices.empty()) {
            group->bindBuffer(vertices);
        }
        if (!normais.empty()) {
            group->bindBuffer(normais);
        }
        if (!textures.empty()) {
            group->bindBuffer(textures, 2);
        }

        if (group->getMaterialName() != "") {
            Material* material = getMaterial(group->getMaterialName());
            group->setTexture(material->getTextureName());
        }
    }
}
