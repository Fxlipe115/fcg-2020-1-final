#ifndef _PROJECTION_H
#define _PROJECTION_H

#include "glm/mat4x4.hpp"

#include "camera.h"
#include "windowparameters.h"

class Projection {
    protected:
        Camera* camera;
        WindowParameters* windowParameters;
    public:
        Projection(Camera* camera, WindowParameters* windowParameters);
        virtual glm::mat4 generateMatrix() = 0;
};

#endif