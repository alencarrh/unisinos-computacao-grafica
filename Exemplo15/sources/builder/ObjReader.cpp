#include "../../headers/builder/ObjReader.h"

Mesh* ObjReader::read(string filename) {
    ifstream arq(filename);
    while (!arq.eof()) {
        string line;
        getline(arq, line);
        stringstream restLine;
        restLine << line;
        string command;
        restLine >> command;
        this->meshBuilder->processLine(command, restLine);
    }

    // no final de passar pro todas as linhas

	return this->meshBuilder->build();
    
}
