/*
*
*   Code inspired by the book Game Physics Cookbook(2017) by Gabor Szauer
*   Chapters 7, 8 and 9
*
*/

#include "collision.h"

#include <glm/vec3.hpp>

bool Collision::boxBox(ObjectInstance* firstCollider, ObjectInstance* secondCollider) {
    return false;
}

bool Collision::boxPlane(ObjectInstance* firstCollider, Plane& plane) {
    return false;
}

bool Collision::boxSphere(ObjectInstance* firstCollider, Sphere& sphere) {
    return false;
}

bool Collision::spherePlane(Sphere& sphere, Plane& plane) {
    glm::vec3 closestPoint = plane.closestPointOnPlane(sphere.getCenter());
    float distSq = norm(sphere.getCenter() - closestPoint);
    float radiusSq = sphere.getRadius() * sphere.getRadius();
    return distSq < radiusSq;
}