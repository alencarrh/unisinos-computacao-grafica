#include "../../headers/builder/MeshBuilder.h"

MeshBuilder::MeshBuilder() {
	functions.insert(make_pair("v", verticeBuilder->process));
	// functions.insert(make_pair("vn", normalBuilder->process));
	// functions.insert(make_pair("vt", textureBuilder->process));
	// functions.insert(make_pair("g", groupBuilder->process));
	// functions.insert(make_pair("f", faceBuilder->process));
}

MeshBuilder::~MeshBuilder() {}
