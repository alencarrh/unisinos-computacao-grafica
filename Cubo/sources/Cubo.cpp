#include "../headers/Cubo.h"

Cubo::Cubo(int width, int height, std::string screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;
}

Cubo::~Cubo() {}

Face* createFace(int vertice1, int vertice2, int vertice3, int vertice4, int normal) {
    Face* face = new Face();
    face->addVerticeId(vertice1);
    face->addVerticeId(vertice2);
    face->addVerticeId(vertice3);
    face->addVerticeId(vertice4);
    face->addNormalId(normal);
    face->addNormalId(normal);
    face->addNormalId(normal);
    face->addNormalId(normal);

    return face;
}


int Cubo::init(GLFWwindow* window) {

    this->mesh = new Mesh();

    this->mesh->addVertice(new glm::vec3(1.0f, 1.0f, 1.0f));
    this->mesh->addVertice(new glm::vec3(-1.0f, 1.0f, 1.0f));
    this->mesh->addVertice(new glm::vec3(-1.0f, -1.0f, 1.0f));
    this->mesh->addVertice(new glm::vec3(1.0f, -1.0f, 1.0f));
    this->mesh->addVertice(new glm::vec3(1.0f, 1.0f, -1.0f));
    this->mesh->addVertice(new glm::vec3(-1.0f, 1.0f, -1.0f));
    this->mesh->addVertice(new glm::vec3(-1.0f, -1.0f, -1.0f));
    this->mesh->addVertice(new glm::vec3(1.0f, -1.0f, -1.0f));

    this->mesh->addNormal(new glm::vec3(1, 0, 0));
    this->mesh->addNormal(new glm::vec3(-1, 0, 0));
    this->mesh->addNormal(new glm::vec3(0, 1, 0));
    this->mesh->addNormal(new glm::vec3(0, -1, 0));
    this->mesh->addNormal(new glm::vec3(0, 0, 1));
    this->mesh->addNormal(new glm::vec3(0, 0, -1));


    Group* group = new Group();

    group->addFace(createFace(0, 1, 2, 3, 4));
    group->addFace(createFace(0, 3, 7, 4, 0));
    group->addFace(createFace(0, 4, 5, 1, 2));
    group->addFace(createFace(2, 1, 5, 6, 1));
    group->addFace(createFace(3, 2, 6, 7, 3));
    group->addFace(createFace(7, 6, 5, 4, 5));

    this->mesh->addGroup(group);


    for (Group* group : this->mesh->getGroups()) {
        vector<float> vertices;
        vector<float> normais;
        for (Face* face : group->getFaces()) {
            for (int verticeID : face->getVertices()) {
                glm::vec3* vertice = this->mesh->vertice(verticeID);
                vertices.push_back(vertice->x);
                vertices.push_back(vertice->y);
                vertices.push_back(vertice->z);
            }
            for (int normalID : face->getNormais()) {
				glm::vec3* normal = this->mesh->normal(normalID);
				normais.push_back(normal->x);
				normais.push_back(normal->y);
				normais.push_back(normal->z);
            }
        }



    }


    return EXIT_SUCCESS;

}


void Cubo::run(GLFWwindow* window) { }

bool Cubo::keepRunning(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void Cubo::finish() {}

int Cubo::width() {
    return this->WIDTH;
}

int Cubo::height() {
    return this->HEIGHT;
}

std::string Cubo::screenTitle() {
    return this->SCREEN_TITLE;
}
