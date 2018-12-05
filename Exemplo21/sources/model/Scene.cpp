#include "../../headers/model/Scene.h"

Scene::Scene(int width, int height, std::string screenTitle) {
    this->WIDTH = width;
    this->HEIGHT = height;
    this->SCREEN_TITLE = screenTitle;

    this->_width = (float)width;
    this->_height = (float)height;
    this->lamp = new Lamp();
}

Scene::~Scene() {
    this->objects.clear();
    this->objects.shrink_to_fit();
}

int Scene::init(GLFWwindow* window) {
    lamp->prepare();
    for (Drawable* obj : this->objects) {
        obj->prepare();
    }

    shader = new ShaderHandler("./shaders/core/obj_vertex.vert", "./shaders/core/obj_fragment.frag");
    lightShader = new ShaderHandler("./shaders/core/light_vertex.vert", "./shaders/core/light_fragment.frag");

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);

    glm::ortho(0.0f, this->_width, 0.0f, this->_height, -1.0f, 1.0f);

    return EXIT_SUCCESS;
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

    // glm::mat4 model(1.0f);
    // model = glm::rotate(model, glm::radians(65.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(10.0f), glm::vec3(0.5f, 1.0f, 0.0f));

    glm::mat4 modelLight(1.0f);
    modelLight = translate(modelLight, (*light->position));

    this->lightShader->use();
    this->lightShader->setMatrix4fv("model", modelLight);
    this->lightShader->setMatrix4fv("view", view);
    this->lightShader->setMatrix4fv("projection", projection);
    this->lightShader->setVec3("lightColor", light->color);

    for (Group* group : this->lamp->mesh()->getGroups()) {
        group->bindVAO();
        glDrawArrays(GL_TRIANGLES, 0, group->numVertices() * 2);
    }

    this->shader->use();
    this->shader->setMatrix4fv("view", view);
    this->shader->setMatrix4fv("projection", projection);
    this->shader->setVec3("lightColor", light->color);
    this->shader->setVec3("lightPos", light->position);
    this->shader->setVec3("viewPos", &camera->position);

    //intensidade da luz
    this->shader->setVec3("light.ambient", light->ambient);
    this->shader->setVec3("light.diffuse", light->diffuse);
    this->shader->setVec3("light.specular", light->specular);

    for (Drawable* obj : this->objects) {

        glm::vec3* A = obj->position();
        glm::mat4 model = translate(glm::mat4(1.0f), *A);

        if (obj->should_rotate()) {
            glm::vec3* B = obj->next_position();

			float w = B->x - A->x;
			float h = B->z - A->z;
			float a = atan2f(w, h) - M_PI / 2;
            glm::mat4 R1 = rotate(glm::mat4(1.0f), a, glm::vec3(0.0f, 1.0f, 0.0f));

            // h = currentPosition->y - nextPosition->y;
			// if (h < 0) {
				// a = atan(w / h) - (M_PI_2);
			// }
			// else {
				// a = atan(w / h) + (M_PI_2);
			// }
            // glm::mat4 R2 = rotate(glm::mat4(1.0f), a, glm::vec3(0.0f, 0.0f, 1.0f));
            model = model * R1;
        }

        this->shader->setMatrix4fv("model", model);

        for (Group* group : obj->mesh()->getGroups()) {
            Material* material = obj->mesh()->getMaterial(group->getMaterialName());
            //propriedades de luz do material
            this->shader->setVec3("material.ambient", material->getAmbienteProperty());
            this->shader->setVec3("material.diffuse", material->getDiffuseProperty());
            this->shader->setVec3("material.specular", material->getSpecularProperty());
            this->shader->setFloat("material.shininess", material->getShininess());

            group->bindVAO();
            group->bindTexture();
            glDrawArrays(GL_TRIANGLES, 0, group->numVertices());
        }
    }

}

bool Scene::keepRunning(GLFWwindow* window) {
    return !glfwWindowShouldClose(window);
}

void Scene::finish() { }
bool fPress = false;

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
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        camera->processKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        camera->processKeyboard(DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && !fPress) {
        fPress = true;
        if (light->on) {
            light->color = new glm::vec3(0.0f, 0.0f, 0.0f);
            light->on = false;
        } else {
            light->color = new glm::vec3(1.0f, 1.0f, 1.0f);
            light->on = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE && fPress) {
        fPress = false;
    }

    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
        light->position = new glm::vec3(camera->position + camera->front);
    }

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        for (Drawable* obj : this->objects) {
            obj->action(FRENTE);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        for (Drawable* obj : this->objects) {
            obj->action(TRAS);
        }
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
