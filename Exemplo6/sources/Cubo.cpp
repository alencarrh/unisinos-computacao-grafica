#include "../headers/Cubo.h"

Cubo::Cubo(int width, int height, std::string screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;
}

Cubo::~Cubo() {}

Face* createFace(int v0, int v1, int v2, int v3, int normal) {
    Face* face = new Face();
    face->addVerticeId(v0);
    face->addVerticeId(v1);
    face->addVerticeId(v3);

    face->addVerticeId(v1);
    face->addVerticeId(v2);
    face->addVerticeId(v3);
    return face;
}

int Cubo::init(GLFWwindow* window) {
    this->mesh = new Mesh();
    int A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7;

    this->mesh->addVertice(new glm::vec3(0.5f, 0.5f, 0.0f));   //A 
    this->mesh->addVertice(new glm::vec3(0.5f, -0.5f, 0.0f));  //B
    this->mesh->addVertice(new glm::vec3(-0.5f, -0.5f, 0.0f)); //C
    this->mesh->addVertice(new glm::vec3(-0.5f, 0.5f, 0.0f));  //D      
    // this->mesh->addVertice(new glm::vec3()); //E
    // this->mesh->addVertice(new glm::vec3()); //F
    // this->mesh->addVertice(new glm::vec3()); //G
    // this->mesh->addVertice(new glm::vec3()); //H

    Group* group = new Group();
    group->addFace(createFace(A, B, C, D, 4));
    this->mesh->addGroup(group);
	
    this->mesh->setShader(new Shader("./shaders/core/vertex.vert", "./shaders/core/fragment.frag"));
	this->mesh->getShader()->use();

	float _width = (float)this->WIDTH;
	float _height = (float)this->HEIGHT;

	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 view(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	
    glm::mat4 projection(1.0f);
	projection = glm::perspective(glm::radians(45.0f), _width / _height, 0.1f, 100.0f);

	this->mesh->getShader()->setMatrix4fv("model", model);
	this->mesh->getShader()->setMatrix4fv("view", view);
	this->mesh->getShader()->setMatrix4fv("projection", projection);

	
    for (Group* group : this->mesh->getGroups()) {
        vector<float> vertices;
        
        for (Face* face : group->getFaces()) {
            for (int verticeID : face->getVertices()) {
                glm::vec3* vertice = this->mesh->vertice(verticeID);
                vertices.push_back(vertice->x);
                vertices.push_back(vertice->y);
                vertices.push_back(vertice->z);
				
                group->countVertice();  
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

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    return EXIT_SUCCESS;
}


void Cubo::run(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->mesh->getShader()->use();
    for (Group* group : this->mesh->getGroups()) {
        glBindVertexArray(group->getVAO());
        glDrawArrays(GL_TRIANGLES, 0, group->getNumVertices());
    }

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
