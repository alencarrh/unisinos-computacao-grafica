#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <string>
#include <GLM/glm.hpp>
#include <vector>
#include "Group.h"

using namespace std;

class Mesh {

private:
    string name;
    string materialsFile;
    vector<Group*> groups;

    vector<glm::vec3*> vertices;
    vector<glm::vec3*> normais;
    vector<glm::vec2*> textures;

    // MaterialHandler* materialsHandler;


public:
    Mesh() {}
    Mesh(string name);
    ~Mesh();

    void prepare();

    glm::vec3* vertice(int id);
    glm::vec3* normal(int id);
    glm::vec2* texture(int id);

    void setName(string name);
    void setMaterialsFile(string materialsFile);
    void setTextures(vector<glm::vec2*>& textures);
    // void setMaterialsHandler(MaterialHandler* handler);

    int addGroup(Group* group);
    int addVertice(glm::vec3* vertice);
    int addNormal(glm::vec3* normal);
    int addTexture(glm::vec2* texture);
    string getMaterialsFile();
    // Material* getMaterial(string materialName);
    vector<Group*>& getGroups();

    void p() {
        cout << "MESH: " << name << endl;

        for (glm::vec3* vertice : vertices) {
            cout << "\tv " << vertice->x << " " << vertice->y << " " << vertice->z << " " << endl;
        }
        for (glm::vec3* normal : normais) {
            cout << "\tn " << normal->x << " " << normal->y << " " << normal->z << " " << endl;
        }
        for (glm::vec2* texture : textures) {
            cout << "\tt " << texture->x << " " << texture->y << " " << endl;
        }

        cout << "\tMaterialFile: " << materialsFile << endl;

        cout << endl << "GROUPS" << endl;

        for (Group* group : groups) {
            group->p();
        }

    }

};

#endif
