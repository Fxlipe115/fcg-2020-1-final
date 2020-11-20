/*
*
*   Code inspired by the book Game Physics Cookbook(2017) by Gabor Szauer
*   Chapters 7, 8 and 9
*
*/

#include "sphere.h"

#include "matrices.h"

Sphere::Sphere(glm::vec3 center, float radius)
 : center(center), radius(radius)
{
}

Sphere::Sphere(ObjectInstance* objectInstance) {
    glm::vec4 objectBoundingBoxMin = glm::vec4(objectInstance->getBoundingBoxMin(), 1.0);
    glm::vec4 objectBoundingBoxMax = glm::vec4(objectInstance->getBoundingBoxMax(), 1.0);
    glm::vec4 radiusVector = (objectBoundingBoxMax - objectBoundingBoxMin) * 0.5f;
    radius = norm(radiusVector);
    center = glm::vec3(objectBoundingBoxMin + radiusVector);
}

glm::vec3 Sphere::getCenter() {
    return center;
}

float Sphere::getRadius() {
    return radius;
}

bool Sphere::isPointInsideSphere(glm::vec3 point) {
    float magSq = norm(point - center);
    float radSq = radius * radius;
    return magSq < radSq;
}

glm::vec3 Sphere::closestPointOnSphere(glm::vec3 point) {
    glm::vec3 sphereToPoint = point - center;
    sphereToPoint = sphereToPoint / norm(sphereToPoint);
    sphereToPoint = sphereToPoint * radius;
    return sphereToPoint + center;
}