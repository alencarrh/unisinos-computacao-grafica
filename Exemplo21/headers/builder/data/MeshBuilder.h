#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "../MeshMediator.h"
#include "../../data/Mesh.h"

#include "FaceBuilder.h"
#include "GroupBuilder.h"
#include "../values/MaterialNameBuilder.h"
#include "../values/MaterialFileBuilder.h"
#include "../values/NormalBuilder.h"
#include "../values/TextureBuilder.h"
#include "../values/VerticeBuilder.h"


typedef void (*_function)(stringstream&);

using namespace std;

class MeshBuilder {

private:
    Mesh* mesh;
	MeshMediator* mediator;
    map<string, _function> functions;

	//builders
	FaceBuilder* faceBuilder;
	GroupBuilder* groupBuilder;
	MaterialNameBuilder* materialNameBuilder;
	MaterialFileBuilder* materialFileBuilder;
	NormalBuilder* normalBuilder;
	TextureBuilder* textureBuilder;
	VerticeBuilder* verticeBuilder;

    _function* function(string command);

public:
    MeshBuilder();
    ~MeshBuilder();

    void processLine(string command, stringstream& line);
    Mesh* build();

};
#endif
