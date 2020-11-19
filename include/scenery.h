#ifndef _SCENERY_H
#define _SCENERY_H

#include <vector>

#include <glm/vec3.hpp>

#include "objectinstance.h"
#include "plane.h"

class Scenery {
    private:
        std::vector<Plane> walls;
        ObjectModel* floorModel;
        ObjectInstance* floor;
        glm::vec3 skyColor;
    public:
        Scenery(glm::vec3 size, VirtualScene* virtualScene);
        ~Scenery();
        std::vector<Plane>& getWalls();
        void draw(GpuProgram* gpuProgram);
};

#endif