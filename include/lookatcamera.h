#ifndef _LOOKATCAMERA_H
#define _LOOKATCAMERA_H

#include <glm/vec3.hpp>

#include "camera.h"

class LookAtCamera : public Camera {
    private:
        glm::vec3 lookAtPoint;
    public:
        LookAtCamera(CameraParameters* cameraParameters);
        bool isFreeCamera() override;
        void moveFront(float speed) override;
        void moveBack(float speed) override;
        void moveLeft(float speed) override;
        void moveRight(float speed) override;
        void moveUp(float speed) override;
        void moveDown(float speed) override;
};

#endif