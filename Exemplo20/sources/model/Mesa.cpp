#include "../../headers/model/Mesa.h"

Mesa::Mesa() {}

Mesa::Mesa(string objFile) {
    this->objReader = new ObjReader();
    this->objFile = objFile;
}

Mesa::~Mesa() {}

void Mesa::prepare() {
    this->_mesh = this->objReader->read(this->objFile);

    this->_mesh->prepare();

	// this->_mesh->p();
}
