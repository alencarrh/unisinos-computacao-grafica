#include "../../headers/reader/ObjReader.h"


ObjReader::ObjReader() {
    this->meshBuilder = new MeshBuilder();
    this->mtlReader = new MtlReader();
}

ObjReader::~ObjReader() {}

Mesh* ObjReader::read(string filename) {
    ifstream arq(filename);

    if (!arq) {
        exit(10);
    }

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
    if (mesh->getMaterialsFile() != "") {
        MaterialHandler* handler = mtlReader->read(mesh->getMaterialsFile());
        mesh->setMaterialsHandler(handler);
    }


    return mesh;

}
