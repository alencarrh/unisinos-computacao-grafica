#ifndef FACE_H
#define FACE_H

#include <vector>
#include <iostream>
using namespace std;
static int VERTICES = 3;

class Face {

private:
    vector<int> vertices;
    vector<int> normais;
    vector<int> textures;

public:
	
    Face();
    ~Face();

    void addVerticeId(int idVertice);
    void addNormalId(int idNormal);
    void addTextureId(int idTexture);

    void setVertices(vector<int>& vec);
    void setNormais(vector<int>& vec);
    void setTextures(vector<int>& vec);
    vector<int>& getVertices();
    vector<int>& getNormais();
    vector<int>& getTextures();

    void p() {
        cout << "Face" << endl << "\tfv ";
        for (int v : vertices) {
            cout << v << " ";
        }
        cout << endl << "\tfn ";
        for (int n : normais) {
            cout << n << " ";
        }
        cout << endl << "\tft ";
        for (int t : textures) {
            cout << t << " ";
        }
        cout << endl;
    }
};
#endif
