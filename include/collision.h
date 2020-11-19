#ifndef _COLLISION_H
#define _COLLISION_H

#include "objectinstance.h"
#include "plane.h"
#include "sphere.h"

class Collision {
    public:
        static bool boxBox(ObjectInstance* firstCollider, ObjectInstance* secondCollider);
        static bool boxPlane(ObjectInstance* firstCollider, Plane& plane);
        static bool boxSphere(ObjectInstance* firstCollider, Sphere& sphere);
        static bool spherePlane(Sphere& sphere, Plane& plane);
};

#endif