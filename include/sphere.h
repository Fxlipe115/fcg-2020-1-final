#ifndef _SPHERE_H
#define _SPHERE_H

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "matrices.h"

#include "objectinstance.h"

class Sphere {
    private:
        glm::vec3 center;
        float radius;
    public:
        Sphere(glm::vec3 center, float radius);
        Sphere(ObjectInstance* objectIntance);
        glm::vec3 getCenter();
        float getRadius();
        bool isPointInsideSphere(glm::vec3 point);
        glm::vec3 closestPointOnSphere(glm::vec3 point);
};

#endif
