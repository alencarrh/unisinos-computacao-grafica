#include "../../headers/builder/FaceBuilder.h"

FaceBuilder::FaceBuilder() {}


FaceBuilder::~FaceBuilder() {}


void FaceBuilder::process(Group* group, std::stringstream& line) {
    stringstream stoken;
    string token;
    string vertice, texture, normal;
    //   line => 237/53/279 236/53/256 205/1/207 206/67/208
    //   line >> token      ->  237/53/279
    //   stoken << token -> vai ter um "buffer" com os trechos separados por "espaço"
    //   getline(stoken, aux, '/')  ->  237
    //   getline(stoken, aux, '/')  ->  53
    //   getline(stoken, aux, '/')  ->  279

    Face* face = new Face();
    while (line >> token) {

        //TODO lidar quando tiver 4 conjutos de V/T/N

        stoken << token;

        getline(stoken, vertice, '/');
        getline(stoken, texture, '/');
        getline(stoken, normal, '/');


        if (vertice != "") {
            face->addVerticeId(stoi(vertice));
        }
        if (texture != "") {
            face->addTextureId(stoi(texture));
        }
        if (normal != "") {
            face->addNormalId(stoi(normal));
        }

    }
}
