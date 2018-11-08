#include "../../headers/reader/ObjReader.h"


ObjReader::ObjReader() {
    this->meshBuilder = new MeshBuilder();
}

ObjReader::~ObjReader() {}

Mesh* ObjReader::read(string filename) {
    ifstream arq(filename);

    if (!arq) {
        exit(EXIT_FAILURE);
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

    return mesh;
}
