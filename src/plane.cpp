/*
*
*   Code inspired by the book Game Physics Cookbook(2017) by Gabor Szauer
*   Chapters 7, 8 and 9
*
*/

#include "plane.h"

#include <glm/vec4.hpp>

#include "matrices.h"

Plane::Plane(glm::vec3 normal, float distanceToOrigin)
 : normal(normal), distanceToOrigin(distanceToOrigin)
{
    glm::vec4 normalizedNormal = glm::vec4(normal, 0.0);
    normalizedNormal /= norm(normalizedNormal);

    normal = glm::vec3(normalizedNormal);
}

glm::vec3 Plane::getNormal() {
    return normal;
}

float Plane::getDistanceToOrigin() {
    return distanceToOrigin;
}

float Plane::distanceToPlane(glm::vec3 point) {
    float pointDistance = dotproduct(glm::vec4(point, 0.0), glm::vec4(normal, 0.0));
    return pointDistance - distanceToOrigin;
}

float Plane::distanceToPlane(Sphere& sphere) {
    float distanceToCenter = distanceToPlane(sphere.getCenter());
    return distanceToCenter - sphere.getRadius();
}

bool Plane::isPointOnPlane(glm::vec3 point) {
    float dot = dotproduct(point, normal);
    return dot - distanceToOrigin == 0.0f;
}

glm::vec3 Plane::closestPointOnPlane(glm::vec3 point) {
    float dot = dotproduct(normal, point);
    float distance = dot - distanceToOrigin;
    return point - normal * distance;
}