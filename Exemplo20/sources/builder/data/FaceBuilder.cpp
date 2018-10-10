#include "../../headers/builder/data/FaceBuilder.h"

FaceBuilder::FaceBuilder() {}


FaceBuilder::~FaceBuilder() {}


void FaceBuilder::process(Group* group, std::stringstream& line) {
    string token;
    string vertice, texture, normal;
    //   line => 237/53/279 236/53/256 205/1/207 206/67/208
    //   line >> token      ->  237/53/279
    //   stoken << token -> vai ter um "buffer" com os trechos separados por "espaço"
    //   getline(stoken, aux, '/')  ->  237
    //   getline(stoken, aux, '/')  ->  53
    //   getline(stoken, aux, '/')  ->  279

    vector<int> vertices;
    vector<int> normais;
    vector<int> textures;

    while (line >> token) {
        stringstream stoken;
        stoken << token;

        getline(stoken, vertice, '/');
        getline(stoken, texture, '/');
        getline(stoken, normal, '/');


        if (vertice != "") {
            vertices.push_back(stoi(vertice) - 1);
        }
        if (texture != "") {
            textures.push_back(stoi(texture) - 1);
        }
        if (normal != "") {
            normais.push_back(stoi(normal) - 1);
        }
    }

    if (vertices.size() == 3) {
        Face* face = new Face();
        face->setVertices(vertices);
        face->setNormais(normais);
        face->setTextures(textures);
        group->addFace(face);
        return;
    }

    if (vertices.size() == 4) {
        Face* face1 = new Face();
        Face* face2 = new Face();

        face1->addVerticeId(vertices[0]);
        face1->addVerticeId(vertices[1]);
        face1->addVerticeId(vertices[3]);

        face2->addVerticeId(vertices[1]);
        face2->addVerticeId(vertices[2]);
        face2->addVerticeId(vertices[3]);

        if (normais.size() == 4) {

            face1->addNormalId(normais[0]);
            face1->addNormalId(normais[1]);
            face1->addNormalId(normais[3]);

            face2->addNormalId(normais[1]);
            face2->addNormalId(normais[2]);
            face2->addNormalId(normais[3]);

        }
        if (textures.size() == 4) {
            face1->addTextureId(textures[0]);
            face1->addTextureId(textures[1]);
            face1->addTextureId(textures[3]);

            face2->addTextureId(textures[1]);
            face2->addTextureId(textures[2]);
            face2->addTextureId(textures[3]);
        }

        group->addFace(face1);
        group->addFace(face2);
    }


}
