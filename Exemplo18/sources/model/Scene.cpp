#include "../../headers/model/Scene.h"

Scene::Scene(int width, int height, std::string screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;

    this->_width = (float)width;
    this->_height = (float)height;
}

Scene::~Scene() {
    this->objs.clear();
    this->objs.shrink_to_fit();
}

int Scene::init(GLFWwindow* window) {
    lamp->prepare();

    for (Drawable* obj : this->objs) {
        obj->prepare();
    }

    shader = new ShaderHandler("./shaders/core/vertex.vert", "./shaders/core/fragment.frag");
    shaderLamp = new ShaderHandler("./shaders/core/vertex_lamp.vert", "./shaders/core/fragment_lamp.frag");

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glm::ortho(0.0f, this->_width, 0.0f, this->_height, 0.1f, 100.0f);

    return EXIT_SUCCESS;
}

void Scene::addObj(Drawable* drawable) {
    this->objs.push_back(drawable);
}

void Scene::run(GLFWwindow* window) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    process_input(window);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(camera->zoom), (float)this->WIDTH / (float)this->HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = camera->getViewMatrix();

    glm::mat4 model(1.0f);
    // model = glm::rotate(model, glm::radians(75.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(10.0f), glm::vec3(0.5f, 1.0f, 0.0f));

    glm::mat4 modelLight(1.0f);
    modelLight = glm::translate(modelLight, (*lightPos));

    this->shaderLamp->use();
    this->shaderLamp->setMatrix4fv("model", modelLight);
    this->shaderLamp->setMatrix4fv("view", view);
    this->shaderLamp->setMatrix4fv("projection", projection);
    this->shaderLamp->setUniform3f("lightColor", lightColor);

    for (Group* group : this->lamp->mesh()->getGroups()) {
        group->bindVAO();
        glDrawArrays(GL_TRIANGLES, 0, group->numVertices());
    }


    this->shader->use();
    this->shader->setMatrix4fv("model", model);
    this->shader->setMatrix4fv("view", view);
    this->shader->setMatrix4fv("projection", projection);
    this->shader->setUniform3f("lightColor", lightColor);
    this->shader->setUniform3f("lightPos", lightPos);
    this->shader->setUniform3f("viewPos", &camera->position);

    //TODO no momento só usamos 1 textura, então vai funcionar, caso queiramos mais de uma por grupo
    //vai ser necessário modificar e linha abaixo
    this->shader->setInt("texture1", 0);

    for (Drawable* obj : this->objs) {
        for (Group* group : obj->mesh()->getGroups()) {
            group->bindTexture();
            group->bindVAO();
            glDrawArrays(GL_TRIANGLES, 0, group->numVertices());
        }
    }

}

bool Scene::keepRunning(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void Scene::finish() { }

void Scene::process_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera->processKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera->processKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera->processKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera->processKeyboard(RIGHT, deltaTime);
    }
}

void Scene::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera->processMouseMovement(xoffset, yoffset);
}

void Scene::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera->processMouseScroll(yoffset);
}

void Scene::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
