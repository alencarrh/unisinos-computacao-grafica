#include "../headers/Group.h"

Group::Group() {}

Group::~Group() {

    //Deleta todas as faces
	this->faces.clear();
    //Reduz o tamanho do meu vector
    this->faces.shrink_to_fit();
}

Face* Group::face(int id) {
    return this->faces[id];
}

int Group::addFace(Face* face) {
    this->faces.push_back(face);
    return this->faces.size() - 1;
}