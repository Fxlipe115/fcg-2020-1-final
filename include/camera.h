#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/vec4.hpp>

#include "cameraparameters.h"

class Camera {
private:
    CameraParameters* parameters;
    
public:
    Camera(CameraParameters* parameters);
    CameraParameters* getParameters();
    glm::vec4 getPosition();
    glm::vec4 getViewVector();
    glm::vec4 getUpVector();
};

#endif