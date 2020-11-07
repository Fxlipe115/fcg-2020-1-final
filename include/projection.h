#ifndef _PROJECTION_H
#define _PROJECTION_H

#include "glm/mat4x4.hpp"

#include "camera.h"
#include "gamewindow.h"

class Projection {
    protected:
        Camera* camera;
        GameWindow* gameWindow;
    public:
        Projection(Camera* camera, GameWindow* gameWindow);
        virtual glm::mat4 generateMatrix() = 0;
};

#endif