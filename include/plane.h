#ifndef _PLANE_H
#define _PLANE_H

#include <glm/vec3.hpp>

class Plane {
    private:
        glm::vec3 normal;
        float distanceToOrigin;
    public:
        Plane(glm::vec3 normal, float distanceToOrigin);
        glm::vec3 getNormal();
        float getDistanceToOrigin();
        float distanceToPlane(glm::vec3 point);
        bool isPointOnPlane(glm::vec3 point);
        glm::vec3 closestPointOnPlane(glm::vec3 point);
};

#endif