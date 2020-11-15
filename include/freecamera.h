#ifndef _FREECAMERA_H
#define _FREECAMERA_H

#include <glm/vec3.hpp>

#include "camera.h"

class FreeCamera : public Camera {
    public:
        FreeCamera(CameraParameters* cameraParameters);
        bool isFreeCamera() override;
        void moveFront(float speed) override;
        void moveBack(float speed) override;
        void moveLeft(float speed) override;
        void moveRight(float speed) override;
        void moveUp(float speed) override;
        void moveDown(float speed) override;
};

#endif