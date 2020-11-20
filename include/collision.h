#ifndef _COLLISION_H
#define _COLLISION_H

#include "axisalignedboundingbox.h"
#include "plane.h"
#include "sphere.h"

class Collision {
    public:
        static bool collision(AxisAlignedBoundingBox& firstBox, AxisAlignedBoundingBox& secondBox);
        static bool collision(AxisAlignedBoundingBox& box, Plane& plane);
        static bool collision(Plane& plane, AxisAlignedBoundingBox& box);
        static bool collision(AxisAlignedBoundingBox& box, Sphere& sphere);
        static bool collision(Sphere& sphere, AxisAlignedBoundingBox& box);
        static bool collision(Sphere& sphere, Plane& plane);
        static bool collision(Plane& plane, Sphere& sphere);
};

#endif