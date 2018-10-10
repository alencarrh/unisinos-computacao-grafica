#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../actions/Runnable.h"
#include "../handler/CameraHandler.h"
#include "../handler/ShaderHandler.h"
#include "../actions/Drawable.h"
#include "Lamp.h"
#include "Light.h"

static CameraHandler* camera = new CameraHandler(glm::vec3(0.0f, 0.0f, 3.0f));

// timing
static float deltaTime = 0.0f; // time between current frame and last frame
static float lastFrame = 0.0f;
static float lastX;
static float lastY;
static bool firstMouse = true;

class Scene : public Runnable {

private:
    GLint WIDTH, HEIGHT;
    float _width, _height;
    std::string SCREEN_TITLE;

    ShaderHandler* shader;
    ShaderHandler* lightShader;

    Lamp* lamp = new Lamp();
    Light* light;

    std::vector<Drawable*> objs;

    static void process_input(GLFWwindow* window);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
    Scene(int width, int height, std::string screenTitle);
    ~Scene() override;

    int init(GLFWwindow* window) override;
    void run(GLFWwindow* window) override;
    bool keepRunning(GLFWwindow* window) override;
    void finish() override;

    void addObj(Drawable* drawable) {
        this->objs.push_back(drawable);
    }

    void setLight(Light* light) {
        this->light = light;
    }

    int width() override {
        return this->WIDTH;
    }

    int height() override {
        return this->HEIGHT;
    }

    std::string screenTitle() override {
        return this->SCREEN_TITLE;
    }

};

#endif
