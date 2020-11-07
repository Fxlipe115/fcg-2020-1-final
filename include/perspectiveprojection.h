#ifndef _PERSPECTIVEPROJECTION_H
#define _PERSPECTIVEPROJECTION_H

#include "glm/mat4x4.hpp"

#include "projection.h"

class PerspectiveProjection : public Projection {
    public:
        PerspectiveProjection(Camera* camera, GameWindow* gameWindow);
        glm::mat4 generateMatrix() override;
};

#endif