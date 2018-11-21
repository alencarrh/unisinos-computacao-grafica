#include "../../headers/reader/MtlReader.h"


MtlReader::MtlReader() {
    this->materialBuilder = new MaterialBuilder();
}

MtlReader::~MtlReader() {
    delete materialBuilder;
}

MaterialHandler* MtlReader::read(string filename) {
    if (handlers.find(filename) != handlers.end()) {
        return handlers[filename];
    }

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

    MaterialHandler* handler = this->materialBuilder->build();
    handlers.insert(make_pair(filename, handler));

    return handler;
}
