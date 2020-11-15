#ifndef _LOOKATCAMERA_H
#define _LOOKATCAMERA_H

#include <glm/vec3.hpp>

#include "camera.h"

class LookAtCamera : public Camera {
    private:
        glm::vec3 lookAtPoint;
    protected:
        glm::vec4 getViewVector() override;
        void setPosition(glm::vec3 position) override;
    public:
        LookAtCamera();
        bool isFreeCamera() override;
};

#endif