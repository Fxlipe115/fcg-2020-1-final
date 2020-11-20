/*
*
*   Code inspired by the book Game Physics Cookbook(2017) by Gabor Szauer
*   Chapters 7, 8 and 9
*
*/

#include "collision.h"
#include "matrices.h"

Collision::Collision() 
 : directionOfCollision({0.0, 0.0, 0.0})
{
}

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

    directionOfCollision = -plane.getNormal();

    return fabsf(dist) <= pLen;
}

bool Collision::collision(Plane& plane, AxisAlignedBoundingBox& box) {
    bool collision = Collision::collision(box, plane);
    directionOfCollision = -directionOfCollision;
    return collision;
}

bool Collision::collision(AxisAlignedBoundingBox& box, Sphere& sphere) {
    glm::vec3 closestPoint = box.closestPointOnBox(sphere.getCenter());
    directionOfCollision = sphere.getCenter() - closestPoint;
    float distSq = norm(directionOfCollision);
    float radiusSq = sphere.getRadius() * sphere.getRadius();
    return distSq < radiusSq;
}

bool Collision::collision(Sphere& sphere, AxisAlignedBoundingBox& box) {
    bool collision = this->collision(box,sphere);
    directionOfCollision = -directionOfCollision;
    return collision;
}

bool Collision::collision(Sphere& sphere, Plane& plane) {
    glm::vec3 closestPoint = plane.closestPointOnPlane(sphere.getCenter());
    directionOfCollision = closestPoint - sphere.getCenter();
    float distSq = norm(directionOfCollision);
    float radiusSq = sphere.getRadius() * sphere.getRadius();
    return distSq < radiusSq;
}

bool Collision::collision(Plane& plane, Sphere& sphere) {
    bool collision = this->collision(sphere, plane);
    directionOfCollision = -directionOfCollision;
    return collision;
}

glm::vec3 Collision::getDirectionOfCollision() {
    return directionOfCollision / norm(directionOfCollision);
}