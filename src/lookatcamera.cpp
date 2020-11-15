#include "lookatcamera.h"

LookAtCamera::LookAtCamera()
 : Camera()
{
}

bool LookAtCamera::isFreeCamera() {
    return false;
}

void LookAtCamera::setPosition(glm::vec3 position) {
    this->lookAtPoint = position;
    float r = distance;
    float y = lookAtPoint.y + r*sin(phi);
    float z = lookAtPoint.z + r*cos(phi)*cos(theta);
    float x = lookAtPoint.x + r*cos(phi)*sin(theta);
    glm::vec4 actualPosition= glm::vec4(x, y, z, 1.0f);
    this->position = actualPosition;
}

glm::vec4 LookAtCamera::getViewVector() {
    return glm::vec4(lookAtPoint, 1.0f) - this->getPosition();
}