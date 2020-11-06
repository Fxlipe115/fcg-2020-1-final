#include "camera.h"

#include <stdexcept>
#include <cmath>


Camera::Camera(CameraParameters* parameters) 
 : parameters(parameters)
{
    if(parameters == nullptr){
        throw std::invalid_argument("Camera parameters must not be null");
    }
}


CameraParameters* Camera::getParameters() {
    return parameters;
}


glm::vec4 Camera::getPosition() {
    float r = this->getParameters()->distance;
    float y = r*sin(this->getParameters()->phi);
    float z = r*cos(this->getParameters()->phi)*cos(this->getParameters()->theta);
    float x = r*cos(this->getParameters()->phi)*sin(this->getParameters()->theta);

    return glm::vec4(x,y,z,1.0f);
}


glm::vec4 Camera::getViewVector() {
    glm::vec4 camera_lookat_l    = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    return camera_lookat_l - this->getPosition();
}


glm::vec4 Camera::getUpVector() {
    return glm::vec4(0.0f,1.0f,0.0f,0.0f);
}