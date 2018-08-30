#include "../headers/System.h"
#include "../headers/ScreenSaver.h"


/*

Screen Saver

*/

int main() {

    ScreenSaver* screenSaver = new ScreenSaver(600, 600, "CGR - GLSL - 03 - Moving Triangle");

    System* system = new System(screenSaver);

    if (system->GLFWInit() != 0) {
        return EXIT_FAILURE;
    }

    // int nrAttributes;
    // glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    // std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    system->run();

}
