#include "camera.h"

#include <cmath>

#include "matrices.h"

Camera::Camera() 
 : theta(0.0f), phi(0.0f), distance(2.0f), 
   nearPlane(-0.1), farPlane(-200.0f)
{
}

Camera::~Camera() {
}

float Camera::getTheta() {
    return theta;
}

void Camera::setTheta(float theta) {
    this->theta = theta;
}

float Camera::getPhi() {
    return phi;
}

void Camera::setPhi(float phi) {
    this->phi = phi;
}

float Camera::getDistance() {
    return distance;
}

void Camera::setDistance(float distance) {
    this->distance = distance;
}

float Camera::getNearPlane() {
    return nearPlane;
}

void Camera::setNearPlane(float nearPlane) {
    this->nearPlane = nearPlane;
}

float Camera::getFarPlane() {
    return farPlane;
}

void Camera::setFarPlane(float farPlane) {
    this->farPlane = farPlane;
}

void Camera::setPosition(glm::vec3 position) {
    this->position = position;
}

glm::vec4 Camera::getPosition() {
    return glm::vec4(position,1.0f);
}

glm::vec4 Camera::getUpVector() {
    return glm::vec4(0.0f,1.0f,0.0f,0.0f);
}

glm::mat4 Camera::getViewMatrix() {
    return Matrix_Camera_View(this->getPosition(), this->getViewVector(), this->getUpVector());
}