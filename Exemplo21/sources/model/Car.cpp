#include "../../headers/model/Car.h"

Car::Car(string objFile, string route) {
    this->objReader = new ObjReader();
    this->objFile = objFile;
    this->current_position = 0;
    this->route = route;
}

Car::~Car() {}

void Car::prepare() {
    this->_mesh = this->objReader->read(this->objFile);
    this->_mesh->prepare();


    ifstream arq(route);

    if (!arq) {
        exit(EXIT_FAILURE);
    }

    while (!arq.eof()) {
        string line;
        stringstream coords;

        getline(arq, line);
        coords << line;

        float x, y, z;
        coords >> x >> y >> z;
        this->positions.push_back(new glm::vec3(x, y, z));
    }

    arq.close();

}

Mesh* Car::mesh() {
    return this->_mesh;
}

glm::vec3* Car::position() {
    return positions[current_position];
}

void Car::action(int action) {
    if (action == FRENTE) {
		current_position = (current_position + 1) % positions.size()-1;
    }
    if (action == TRAS) {
		current_position = (current_position - 1) % positions.size();
    }
}
