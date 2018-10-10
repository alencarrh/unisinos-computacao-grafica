#include "../../headers/model/Cube.h"

Cube::Cube() {}

Cube::~Cube() {
    delete this->_mesh;
}

Face* createFace(int v0, int v1, int v2, int v3, int normal) {
    Face* face = new Face();
    face->addVerticeId(v0);
    face->addVerticeId(v1);
    face->addVerticeId(v3);
    face->addTextureId(3);
    face->addTextureId(2);
    face->addTextureId(0);
    face->addNormalId(normal);
    face->addNormalId(normal);
    face->addNormalId(normal);

    face->addVerticeId(v1);
    face->addVerticeId(v2);
    face->addVerticeId(v3);
    face->addTextureId(2);
    face->addTextureId(1);
    face->addTextureId(0);
    face->addNormalId(normal);
    face->addNormalId(normal);
    face->addNormalId(normal);


    return face;
}

void Cube::prepare() {

    this->_mesh = new Mesh("default");
    int A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7;
    float escale = 2;

    this->_mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, 1.0f / escale)); //A
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, 1.0f / escale)); //B
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, 1.0f / escale)); //C
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, 1.0f / escale)); //D      
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, -1.0f / escale)); //E
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, -1.0f / escale)); //F
    this->_mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, -1.0f / escale)); //G
    this->_mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, -1.0f / escale)); //H


    this->_mesh->addNormal(new glm::vec3(1.0, 0.0, 0.0));
    this->_mesh->addNormal(new glm::vec3(-1.0, 0.0, 0.0));
    this->_mesh->addNormal(new glm::vec3(0.0, 1.0, 0.0));
    this->_mesh->addNormal(new glm::vec3(0.0, -1.0, 0.0));
    this->_mesh->addNormal(new glm::vec3(0.0, 0.0, 1.0));
    this->_mesh->addNormal(new glm::vec3(0.0, 0.0, -1.0));

    this->_mesh->addTexture(new glm::vec2(1.0, 1.0));
    this->_mesh->addTexture(new glm::vec2(1.0, 0.0));
    this->_mesh->addTexture(new glm::vec2(0.0, 0.0));
    this->_mesh->addTexture(new glm::vec2(0.0, 1.0));

    this->_mesh->setMaterialsFile("teste.mtl");


    Material* material = new Material("teste");
    material->setAmbienteProperty(new glm::vec3(1.0f));
    material->setDiffuseProperty(new glm::vec3(1.0f));
    material->setSpecularProperty(new glm::vec3(1.0f));
    material->setShininess(128.0f);
    material->setTextureName("./files/textures/container.jpg");

    MaterialHandler* handler = new MaterialHandler();
    handler->addMaterial(material);

    this->_mesh->setMaterialsHandler(handler);

    /*

   A--------D
  /|       /|
 / |      / |
B--------C  |
|  |     |  |
|  E-----|--H
| /      | /
|/       |/
F--------G


     */

    Group* group = new Group("default");
    group->setMaterialName("teste");
    group->addFace(createFace(A, B, C, D, 4)); // 1 2 3 4   ->
    group->addFace(createFace(A, D, H, E, 0)); // 1 4 8 5   ->
    group->addFace(createFace(A, E, F, B, 2)); // 1 5 6 2   ->
    group->addFace(createFace(C, B, F, G, 1)); // 3 2 6 7   -> 
    group->addFace(createFace(D, C, G, H, 3)); // 4 3 7 8   ->
    group->addFace(createFace(H, G, F, E, 5)); // 8 7 6 5   ->

    this->_mesh->addGroup(group);

    this->_mesh->prepare();
}
