#ifndef _OBJECTMODEL_H
#define _OBJECTMODEL_H

#include <vector>

#include <glad/glad.h>
#include <tiny_obj_loader.h>

#include "sceneobject.h"
#include "virtualscene.h"

class ObjectModel {
    private:
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
        std::vector<std::string> meshNames;
        VirtualScene* virtualScene;

    public:
        ObjectModel(const char* filename, const char* basepath = NULL, bool triangulate = true);
        void computeNormals();
        void buildTrianglesAndAddToVirtualScene(VirtualScene* virtualScene);
        void printObjectModelInfo();
        void draw();
};

#endif