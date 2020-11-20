#ifndef _COLLISION_H
#define _COLLISION_H

#include <glm/vec3.hpp>

#include "axisalignedboundingbox.h"
#include "plane.h"
#include "sphere.h"

class Collision {
    private:
        glm::vec3 directionOfCollision;
    public:
        Collision();
        bool collision(AxisAlignedBoundingBox& firstBox, AxisAlignedBoundingBox& secondBox);
        bool collision(AxisAlignedBoundingBox& box, Plane& plane);
        bool collision(Plane& plane, AxisAlignedBoundingBox& box);
        bool collision(AxisAlignedBoundingBox& box, Sphere& sphere);
        bool collision(Sphere& sphere, AxisAlignedBoundingBox& box);
        bool collision(Sphere& sphere, Plane& plane);
        bool collision(Plane& plane, Sphere& sphere);
        glm::vec3 getDirectionOfCollision();
};

#endif