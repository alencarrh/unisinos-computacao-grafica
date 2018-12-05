#include "ShaderHandler.h"
#include "utils.h"

float CURVE_DISTANCE = 15.0f;

GLuint VAO_CP, VBO_CP; //Control points
GLuint VAO_BSLINE, VBO_BSLINE; //B-Splines
GLuint VAO_BSLINE_IN, VBO_BSLINE_IN; //B-Splines internal
GLuint VAO_BSLINE_EX, VBO_BSLINE_EX; //B-Splines external

// others attributes
vector<float> control_points, bspline, bspline_in, bspline_ex;
ShaderHandler* shader;
ShaderHandler* cp_shader;


//methods
int load_shaders();
void setup_vao_vbos();
void draw();
void finish(GLFWwindow* window);
void to_obj();
//handlers
void keyboard_input_handler(GLFWwindow* window);


//main function
int main() {
    init();
    define_callbacks(window);
    load_shaders();
    setup_vao_vbos();
    while (keep_running(window)) {
        clear_screen();
        keyboard_input_handler(window);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    finish(window);
}


int load_shaders() {
    shader = new ShaderHandler("./shaders/core/vertex.vert", "./shaders/core/fragment.frag");

    if (!shader) {
        std::cout << "ERROR: Failed to load shaders" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    shader->use();
    shader->setMatrix4fv("projection", projection);

    return EXIT_SUCCESS;
}


void setup_vao_vbos() {
    //generate
    gen_vao(VAO_CP);
    gen_vao(VAO_BSLINE);
    gen_vao(VAO_BSLINE_IN);
    gen_vao(VAO_BSLINE_EX);
    gen_vbo(VBO_CP);
    gen_vbo(VBO_BSLINE);
    gen_vbo(VBO_BSLINE_EX);
    gen_vbo(VBO_BSLINE_IN);

    bind_vbo(VAO_CP, VBO_CP, control_points);
    bind_vbo(VAO_BSLINE, VBO_BSLINE, bspline);
    bind_vbo(VAO_BSLINE_IN, VBO_BSLINE_IN, bspline_in);
    bind_vbo(VAO_BSLINE_EX, VBO_BSLINE_EX, bspline_ex);

}

void update_bspline() {
    // x  y  z
    // 0  1  2
    // 3  4  5
    // 6  7  8
    // 9 10 11

    bspline.clear();
    int size = control_points.size();

    for (int i = 0; i < size + 3; i += 3) {
        for (float t = 0; t < 1; t += 0.05f) {

            float t_pow_3 = pow(t, 3);
            float t_pow_2 = pow(t, 2);

            float x = calculate_bspline_point(t, t_pow_3, t_pow_2,
                                              control_points[(i + 0) % size],
                                              control_points[(i + 3) % size],
                                              control_points[(i + 6) % size],
                                              control_points[(i + 9) % size]
            );

            float y = calculate_bspline_point(t, t_pow_3, t_pow_2,
                                              control_points[(i + 0 + 1) % size],
                                              control_points[(i + 3 + 1) % size],
                                              control_points[(i + 6 + 1) % size],
                                              control_points[(i + 9 + 1) % size]
            );
            float z = calculate_bspline_point(t, t_pow_3, t_pow_2,
                                              control_points[(i + 0 + 2) % size],
                                              control_points[(i + 3 + 2) % size],
                                              control_points[(i + 6 + 2) % size],
                                              control_points[(i + 9 + 2) % size]
            );


            bspline.push_back(x);
            bspline.push_back(y);
            bspline.push_back(z);
        }
    }

    bind_vbo(VAO_BSLINE, VBO_BSLINE, bspline);

}


void update_bspline_in_ex() {
    bspline_ex.clear();
    bspline_in.clear();
    int size = bspline.size();

    for (int i = 0; i < size - 3; i += 3) {

        float Ax = bspline[(i + 0) % size];
        float Ay = bspline[(i + 1) % size];

        float Bx = bspline[(i + 3) % size];
        float By = bspline[(i + 4) % size];

        //->
        //AB
        float w = Bx - Ax;
        float h = By - Ay;
        float a = atan(h / w);

        float internalAngle, externalAngle;

        if (w < 0) {
            internalAngle = a + M_PI / 2;
            externalAngle = a - M_PI / 2;
        } else {
            internalAngle = a - M_PI / 2;
            externalAngle = a + M_PI / 2;
        }


        float internalCx = cos(internalAngle) * CURVE_DISTANCE + Ax;
        float internalCy = sin(internalAngle) * CURVE_DISTANCE + Ay;

        bspline_in.push_back(internalCx);
        bspline_in.push_back(internalCy);
        bspline_in.push_back(0.0f); // TODO


        float externalCx = cos(externalAngle) * CURVE_DISTANCE + Bx;
        float externalCy = sin(externalAngle) * CURVE_DISTANCE + By;

        bspline_ex.push_back(externalCx);
        bspline_ex.push_back(externalCy);
        bspline_ex.push_back(0.0f); // TODO

    }

    bind_vbo(VAO_BSLINE_IN, VBO_BSLINE_IN, bspline_in);
    bind_vbo(VAO_BSLINE_EX, VBO_BSLINE_EX, bspline_ex);
}


void draw() {
    bind_vao(VAO_CP);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, (float)control_points.size() / 3);

    // B-Splines
    bind_vao(VAO_BSLINE);
    glDrawArrays(GL_LINE_STRIP, 0, (float)bspline.size() / 3);

    // B-Splines external
    bind_vao(VAO_BSLINE_EX);
    glDrawArrays(GL_LINE_STRIP, 0, (float)bspline_ex.size() / 3);

    // B-Splines internal
    bind_vao(VAO_BSLINE_IN);
    glDrawArrays(GL_LINE_STRIP, 0, (float)bspline_in.size() / 3);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x_current_pos, y_current_pos;
        glfwGetCursorPos(window, &x_current_pos, &y_current_pos);

        if (x_last_pos == x_current_pos && x_last_pos == x_current_pos) {
            //just to not repeat
            return;
        }

        cout << "x: " << x_current_pos << "  y: " << y_current_pos << endl;
        x_last_pos = x_current_pos;
        y_last_pos = y_current_pos;

        control_points.push_back(x_current_pos);
        control_points.push_back(y_current_pos);
        control_points.push_back(0.0f);

        bind_vbo(VAO_CP, VBO_CP, control_points);
        update_bspline();
        update_bspline_in_ex();
    }
}

void keyboard_input_handler(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        control_points.clear();
        bspline.clear();
        bspline_in.clear();
        bspline_ex.clear();
        bind_vbo(VAO_CP, VBO_CP, control_points);
        bind_vbo(VAO_BSLINE, VBO_BSLINE, bspline);
        bind_vbo(VAO_BSLINE_IN, VBO_BSLINE_IN, bspline_in);
        bind_vbo(VAO_BSLINE_EX, VBO_BSLINE_EX, bspline_ex);
    }


    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        to_obj();
    }
}

void finish(GLFWwindow* window) {
    del_vao(VAO_CP);
    del_vao(VAO_BSLINE);
    del_vao(VAO_BSLINE_IN);
    del_vao(VAO_BSLINE_EX);
    del_vbo(VBO_CP);
    del_vbo(VBO_BSLINE);
    del_vbo(VBO_BSLINE_EX);
    del_vbo(VBO_BSLINE_IN);
}

string path = "../Exemplo21/";
string BSLINE = path + "curva.txt";
string OBJ_FILE = path + "pista.obj";
string MATERIAL_FILE = path + "pista.mtl";
string MATERIAL_NAME = "NOME_DO_MATERIAL_AQUI";
string GROUP_NAME = "GRUPO";
string TEXTURE_FILE = "pista.jpg";

void to_obj() {
    ofstream material(MATERIAL_FILE);
    material << "newmtl " << MATERIAL_NAME << endl;
    material << "Ka 0.7 0.7 0.7" << endl;
    material << "Kd 0.9 0.9 0.9" << endl;
    material << "Ks 1.0 1.0 1.0" << endl;
    material << "Ns 64.0" << endl;
    material << "map_Kd " << TEXTURE_FILE << endl;
    material.close();

    ofstream curva(BSLINE);
    for (int i = 0; i < bspline.size(); i += 3) {
        curva << bspline[i] * GLOBAL_SCALE  << " " << bspline[i + 2]  << " " << bspline[i+1] * GLOBAL_SCALE << endl;
    }
    curva.close();


    ofstream obj(OBJ_FILE);
    obj << "mtllib " << MATERIAL_FILE << endl;
    obj << "g " << GROUP_NAME << endl;
    obj << "usemtl " << MATERIAL_NAME << endl;

    obj << "vt 0.0 0.0" << endl;
    obj << "vt 0.0 1.0" << endl;
    obj << "vt 1.0 0.0" << endl;
    obj << "vt 1.0 1.0" << endl;

    int size = bspline_in.size();
    int vertices_size = size / 3;
    for (int i = 0; i < size; i += 3) {
        obj << "v " << (bspline_in[i] * GLOBAL_SCALE) << " " << bspline_in[i + 2] << " " << (bspline_in[i + 1] * GLOBAL_SCALE)
            << endl;
    }
    for (int i = 0; i < size; i += 3) {
        obj << "v " << (bspline_ex[i] * GLOBAL_SCALE) << " " << bspline_ex[i + 2] << " " << (bspline_ex[i + 1] * GLOBAL_SCALE)
            << endl;
    }

    for (int i = 1; i <= size / 3 - 3; i ++) {
        obj << "f " << i << "/1 " << (i + 1) << "/2 " << i + vertices_size << "/4" << endl;
        obj << "f " << i + vertices_size << "/4 " << (i + 1) << "/2 " << i + 1 + vertices_size << "/3" << endl;
    }

    obj.close();
}
