#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/vec4.hpp>

#include "glm/mat4x4.hpp"

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
    glm::mat4 getViewMatrix();
    virtual bool isFreeCamera() = 0;
    virtual void moveFront(float speed) = 0;
    virtual void moveBack(float speed) = 0;
    virtual void moveLeft(float speed) = 0;
    virtual void moveRight(float speed) = 0;
    virtual void moveUp(float speed) = 0;
    virtual void moveDown(float speed) = 0;
};

#endif