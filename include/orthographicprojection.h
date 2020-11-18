#ifndef _ORTHOGRAPHICPROJECTION_H
#define _ORTHOGRAPHICPROJECTION_H

#include "glm/mat4x4.hpp"

#include "projection.h"

class OrthographicProjection : public Projection {
    public:
        OrthographicProjection(Camera* camera, WindowParameters* windowParameters);
        ~OrthographicProjection();
        glm::mat4 generateMatrix() override;
};

#endif