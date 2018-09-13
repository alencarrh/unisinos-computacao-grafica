#include "../headers/Cubo.h"

Cubo::Cubo(int width, int height, std::string screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;
}

Cubo::~Cubo() {}

Face* createFace(int v1, int v2, int v3, int v4, int normal) {
    Face* face = new Face();
    face->addVerticeId(v1);
    face->addVerticeId(v2);
    face->addVerticeId(v3);

    face->addVerticeId(v1);
    face->addVerticeId(v4);
    face->addVerticeId(v3);
    return face;
}

int val = 0;

int Cubo::init(GLFWwindow* window) {

    this->mesh = new Mesh();

    float escale = 2;

    int A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7;

    this->mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, 1.0f / escale)); //A
    this->mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, 1.0f / escale)); //B
    this->mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, 1.0f / escale)); //C
    this->mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, 1.0f / escale)); //D      
    this->mesh->addVertice(new glm::vec3(1.0f / escale, 1.0f / escale, -1.0f / escale)); //E
    this->mesh->addVertice(new glm::vec3(-1.0f / escale, 1.0f / escale, -1.0f / escale)); //F
    this->mesh->addVertice(new glm::vec3(-1.0f / escale, -1.0f / escale, -1.0f / escale)); //G
    this->mesh->addVertice(new glm::vec3(1.0f / escale, -1.0f / escale, -1.0f / escale)); //H

    this->mesh->addNormal(new glm::vec3(1, 0, 0));
    this->mesh->addNormal(new glm::vec3(-1, 0, 0));
    this->mesh->addNormal(new glm::vec3(0, 1, 0));
    this->mesh->addNormal(new glm::vec3(0, -1, 0));
    this->mesh->addNormal(new glm::vec3(0, 0, 1));
    this->mesh->addNormal(new glm::vec3(0, 0, -1));


    Group* group = new Group();

    group->addFace(createFace(A, B, C, D, 4));
    group->addFace(createFace(A, E, H, D, 0));
    group->addFace(createFace(A, E, F, B, 2));
    group->addFace(createFace(B, F, G, C, 1));
    group->addFace(createFace(C, G, H, D, 3));
    group->addFace(createFace(E, F, G, H, 5));
    /*
   a-------d
  /|      /|
 / |     / |
b--|----c  |
|  e----|--h
| /     | /
f-------g
*/
	
    this->mesh->addGroup(group);
    this->mesh->setShader(new Shader("./shaders/core/vertex.vert", "./shaders/core/fragment.frag"));
    // this->mesh->setShaderWhite(new Shader("./shaders/core/vertex.vert", "./shaders/core/fragment_white.frag"));


    float _width = (float)this->WIDTH;
    float _height = (float)this->HEIGHT;

    // glm::mat4 projection = glm::perspective(glm::radians(45.0f), _width / _height, 0.1f, 100.0f);
    // this->mesh->getShader()->setMatrix4fv("projection", glm::value_ptr(projection));
    // this->mesh->getShaderWhite()->setMatrix4fv("projection", glm::value_ptr(projection));


    // glm::ortho(0.0f, _width, 0.0f, _height, 0.1f, 100.0f);

    // glm::mat4 view;
    // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    // glm::mat4 projection;
    // projection = glm::perspective(glm::radians(45.0f), _width / _height, 0.1f, 100.0f);

    // this->mesh->getShader()->setMatrix4fv("model", glm::value_ptr(model));
    // this->mesh->getShader()->setMatrix4fv("view", glm::value_ptr(view));
    // this->mesh->getShader()->setMatrix4fv("projection", glm::value_ptr(projection));

    // this->mesh->getShaderWhite()->setMatrix4fv("model", glm::value_ptr(model));
    // this->mesh->getShaderWhite()->setMatrix4fv("view", glm::value_ptr(view));
    // this->mesh->getShaderWhite()->setMatrix4fv("projection", glm::value_ptr(projection));

    for (Group* group : this->mesh->getGroups()) {
        vector<float> vertices;
        // vector<float> normais;
        for (Face* face : group->getFaces()) {
            for (int verticeID : face->getVertices()) {
                val++;
                glm::vec3* vertice = this->mesh->vertice(verticeID);
                vertices.push_back(vertice->x);
                vertices.push_back(vertice->y);
                vertices.push_back(vertice->z);
            }
        }

        GLuint VAO, VBOvert;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBOvert);

        glBindBuffer(GL_ARRAY_BUFFER, VBOvert);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

        glEnableVertexAttribArray(0);

        group->setVAO(&VAO);
    }

    // printf("val: %d", val);
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    return EXIT_SUCCESS;


    /*
     
     calcular normal:
           
            -> norma(v) = raiz ( v.x² + v.y² )

        cos teta -> Produto Escalar entre Normal e L (L = LUZ - PONTO)





     */

}


void Cubo::run(GLFWwindow* window) {
	glm::mat4 view;
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, -3.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->mesh->getShader()->use();
    this->mesh->getShader()->setMat4("view", view);
    for (Group* group : this->mesh->getGroups()) {
        glBindVertexArray(group->getVAO());
        glDrawArrays(GL_TRIANGLES, 0, val);
    }

    // this->mesh->getShaderWhite()->use();
    // this->mesh->getShaderWhite()->setMat4("view", view);
    // for (Group* group : this->mesh->getGroups()) {
        // glBindVertexArray(group->getVAO());
        // glDrawArrays(GL_LINES, 0, val);
    // }


}

bool Cubo::keepRunning(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void Cubo::finish() {
    delete this->mesh;
}

int Cubo::width() {
    return this->WIDTH;
}

int Cubo::height() {
    return this->HEIGHT;
}

std::string Cubo::screenTitle() {
    return this->SCREEN_TITLE;
}
