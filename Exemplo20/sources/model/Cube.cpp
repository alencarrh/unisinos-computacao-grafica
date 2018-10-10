#include "../../headers/model/Cube.h"

Cube::Cube() {}

Cube::~Cube() {
    delete this->_mesh;
}

void createFace(int v0, int v1, int v2, int v3, int normal, Group* group) {
    Face* face1 = new Face();
    face1->addVerticeId(v0);
    face1->addVerticeId(v1);
    face1->addVerticeId(v3);
    face1->addTextureId(3);
    face1->addTextureId(2);
    face1->addTextureId(0);
    face1->addNormalId(normal);
    face1->addNormalId(normal);
    face1->addNormalId(normal);

	Face* face2 = new Face();
    face2->addVerticeId(v1);
    face2->addVerticeId(v2);
    face2->addVerticeId(v3);
    face2->addTextureId(2);
    face2->addTextureId(1);
    face2->addTextureId(0);
    face2->addNormalId(normal);
    face2->addNormalId(normal);
    face2->addNormalId(normal);

	group->addFace(face1);
	group->addFace(face2);
}

void Cube::prepare() {

    this->_mesh = new Mesh("default");
    int A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7;
    float escale = 1;

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

    this->_mesh->addTexture(new glm::vec2(1.0, 1.0)); //0
    this->_mesh->addTexture(new glm::vec2(1.0, 0.0)); //1
    this->_mesh->addTexture(new glm::vec2(0.0, 0.0)); //2
    this->_mesh->addTexture(new glm::vec2(0.0, 1.0)); //3

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
    createFace(A, B, C, D, 4, group); // 1 2 3 4   -> (1/4/5 2/3/5 4/1/5) (2/3/5 3/2/5 4/1/5)
    createFace(A, D, H, E, 0, group); // 1 4 8 5   -> (1/4/1 4/3/1 5/1/1) (4/3/1 8/2/1 5/1/1)
    createFace(A, E, F, B, 2, group); // 1 5 6 2   -> (1/4/2 5/3/2 2/1/2) (5/3/2 6/2/2 2/1/2)
    createFace(C, B, F, G, 1, group); // 3 2 6 7   -> (3/4/1 2/3/1 7/1/1) (2/3/1 6/2/1 7/1/1)
    createFace(D, C, G, H, 3, group); // 4 3 7 8   -> (4/4/3 3/3/3 8/1/3) (3/3/3 7/2/3 8/1/3)
    createFace(H, G, F, E, 5, group); // 8 7 6 5   -> (8/4/5 7/3/5 5/1/5) (7/3/5 6/2/5 5/1/5)

    this->_mesh->addGroup(group);

    this->_mesh->prepare();

	this->_mesh->p();
}
