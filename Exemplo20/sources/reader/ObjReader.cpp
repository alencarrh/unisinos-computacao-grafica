#include "../../headers/reader/ObjReader.h"


ObjReader::ObjReader() {
    this->meshBuilder = new MeshBuilder();
    this->meshBuilder->init();
    
    this->mtlReader = new MtlReader();
}

ObjReader::~ObjReader() {}

Mesh* ObjReader::read(string filename) {
    ifstream arq(filename);

    while (!arq.eof()) {
        string line;
        stringstream restLine;
        string command;

        getline(arq, line);
        restLine << line;

        restLine >> command;

        this->meshBuilder->processLine(command, restLine);
    }

    Mesh* mesh = this->meshBuilder->build();

    MaterialHandler* handler = mtlReader->read(mesh->getMaterialsFile());

    mesh->setMaterialsHandler(handler);
    return mesh;

}
