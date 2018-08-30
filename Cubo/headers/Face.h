#ifndef FACE_H
#define FACE_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>

using namespace std;

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


};
#endif