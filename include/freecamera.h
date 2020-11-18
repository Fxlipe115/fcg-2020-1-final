#ifndef _FREECAMERA_H
#define _FREECAMERA_H

#include <glm/vec3.hpp>

#include "camera.h"

class FreeCamera : public Camera {
    protected:
        glm::vec4 getViewVector() override;
    public:
        FreeCamera();
        ~FreeCamera();
        bool isFreeCamera() override;
};

#endif