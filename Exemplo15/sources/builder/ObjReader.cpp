#ifndef OBJ_READER_H
#define OBJ_READER_H

//includes para leitura do arquivo
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "../../headers/builder/MeshBuilder.h"
#include "../../headers/data/Mesh.h"

using namespace std;

class ObjReader {

private:
	MeshBuilder* meshBuilder;

public:
	//ObjReader(string path, string fileName); //Para criar o objReader ,é preciso indicar o arquivo

	Mesh* read(string filename) {
		ifstream arq(filename);
		while (!arq.eof()) {
			string line;
			getline(arq, line);
			stringstream restLine;
			restLine << line;
			string command;
			restLine >> command;
			//meshBuilder->processLine(command, line);
		}

		// no final de passar pro todas as linhas

		//meshBuilder->build();
	}



};



#endif
