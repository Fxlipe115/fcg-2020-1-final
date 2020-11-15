#ifndef _CAMERAPARAMETERS_H
#define _CAMERAPARAMETERS_H

#include <glm/vec3.hpp>

struct CameraParameters
{
    CameraParameters();
    glm::vec3 position;
    float theta;
    float phi;
    float distance;
    float nearPlane;
    float farPlane;
};

#endif