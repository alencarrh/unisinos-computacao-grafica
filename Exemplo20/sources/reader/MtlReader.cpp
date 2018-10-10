#include "../../headers/reader/MtlReader.h"

Mesh* MtlReader::read(string filename) {
    ifstream arq(filename);
    while (!arq.eof()) {
        string line;
        getline(arq, line);
        stringstream restLine;
        restLine << line;
        string command;
        restLine >> command;
        this->materialBuilder->processLine(command, restLine);
    }

    return NULL;
}
