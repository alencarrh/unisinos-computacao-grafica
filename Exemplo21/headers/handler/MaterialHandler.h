#ifndef MATERIAL_HANDLER_H
#define MATERIAL_HANDLER_H

#include <map>
#include <string>
#include "../data/Material.h"

using namespace std;

class MaterialHandler {

private:
    map<string, Material*> materials;
    Material* defaultMaterial;

public:
    MaterialHandler();
    ~MaterialHandler();

    void addMaterial(Material* material);
    Material* getMaterial(string materialName);

};

#endif
