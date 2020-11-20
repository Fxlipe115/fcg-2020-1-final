/*
*
*   Code inspired by the book Game Physics Cookbook(2017) by Gabor Szauer
*   Chapters 7, 8 and 9
*
*/

#include <glm/vec3.hpp>

#include "collision.h"
#include "matrices.h"


bool Collision::collision(AxisAlignedBoundingBox& firstBox, AxisAlignedBoundingBox& secondBox) {
    glm::vec3 aMin = firstBox.getMin();
    glm::vec3 aMax = firstBox.getMax();
    glm::vec3 bMin = secondBox.getMin();
    glm::vec3 bMax = secondBox.getMax();

    return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
           (aMin.y <= bMax.y && aMax.y >= bMin.y) &&
           (aMin.z <= bMax.z && aMax.z >= bMin.z);
}

bool Collision::collision(AxisAlignedBoundingBox& box, Plane& plane) {
    float pLen = box.getSize().x * fabsf(plane.getNormal().x) +
                 box.getSize().y * fabsf(plane.getNormal().y) +
                 box.getSize().z * fabsf(plane.getNormal().z);
    float dot = dotproduct(plane.getNormal(), box.getOrigin());
    float dist = dot - plane.getDistanceToOrigin();

    return fabsf(dist) <= pLen;
}

bool Collision::collision(Plane& plane, AxisAlignedBoundingBox& box) {
    return Collision::collision(box, plane);
}

bool Collision::collision(AxisAlignedBoundingBox& box, Sphere& sphere) {
    glm::vec3 closestPoint = box.closestPointOnBox(sphere.getCenter());
    float distSq = norm(sphere.getCenter() - closestPoint);
    float radiusSq = sphere.getRadius() * sphere.getRadius();
    return distSq < radiusSq;
}

bool Collision::collision(Sphere& sphere, AxisAlignedBoundingBox& box) {
    return Collision::collision(box,sphere);
}

bool Collision::collision(Sphere& sphere, Plane& plane) {
    glm::vec3 closestPoint = plane.closestPointOnPlane(sphere.getCenter());
    float distSq = norm(sphere.getCenter() - closestPoint);
    float radiusSq = sphere.getRadius() * sphere.getRadius();
    return distSq < radiusSq;
}

bool Collision::collision(Plane& plane, Sphere& sphere) {
    return Collision::collision(sphere, plane);
}