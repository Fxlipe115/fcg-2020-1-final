#ifndef _COLLISION_H
#define _COLLISION_H

#include "objectinstance.h"
#include "plane.h"
#include "sphere.h"

class Collision {
    public:
        static bool collision(ObjectInstance* firstCollider, ObjectInstance* secondCollider);
        static bool collision(ObjectInstance* firstCollider, Plane& plane);
        static bool collision(ObjectInstance* firstCollider, Sphere& sphere);
        static bool collision(Sphere& sphere, Plane& plane);
        static bool collision(Plane& plane, Sphere& sphere);
};

#endif