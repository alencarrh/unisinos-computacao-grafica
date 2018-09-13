#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include "Face.h"

using namespace std;

class Group {

private:
    vector<Face*> faces;
	GLuint VAO;

public:

    Group();
    ~Group();

    Face* face(int id);
    int addFace(Face* face);

    vector<Face*>& getFaces() {
        return faces;
    };
    
    void setVAO(GLuint* VAO) {
		this->VAO = *VAO;
    }
    
    GLuint& getVAO() {
		return this->VAO;
    }

};

#endif
