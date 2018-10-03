#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include "../../headers/data/Mesh.h"
#include "../../headers/builder/FaceBuilder.h"
#include "../../headers/builder/GroupBuilder.h"
#include "../../headers/builder/VerticeBuilder.h"
#include "../../headers/builder/NormalBuilder.h"
#include "../../headers/builder/TextureBuilder.h"
#include "../../headers/builder/MaterialBuilder.h"

using namespace std;

typedef int(*_function)(stringstream&);
static map<string, _function> functions;

class MeshBuilder {

private:
	FaceBuilder* faceBuilder;
	GroupBuilder* groupBuilder;
	VerticeBuilder* verticeBuilder;
	NormalBuilder* normalBuilder;
	TextureBuilder* textureBuilder;
	MaterialBuilder* materialBuilder;


	MeshBuilder() {
		/*functions.insert(make_pair("v", &verticeBuilder::process));
		functions.insert(make_pair("vn", &normalBuilder::process));
		functions.insert(make_pair("vt", &textureBuilder::process));
		functions.insert(make_pair("g", &groupBuilder::process));
		functions.insert(make_pair("f", &faceBuilder::process));*/
	}

	_function* function(string command) {
		return function[command]; //TODO fazer um find e retornar NULL se não encontrar
	}

	void processLine(string command, stringstream& line) {
		//function(command)(line);
	}

	Mesh* build() {
		//cria a mesh e retorna
		//mesh->setVertices(verticeBuilder->build());
		//return mesh;
	}

};

#endif
