#include "perspectiveprojection.h"

#include "matrices.h"

PerspectiveProjection::PerspectiveProjection(Camera* camera, WindowParameters* windowParameters)
 : Projection(camera, windowParameters)
{
}

PerspectiveProjection::~PerspectiveProjection() {
}

glm::mat4 PerspectiveProjection::generateMatrix() {
    float field_of_view = 3.141592 / 3.0f;
    float screenRatio = windowParameters->screenRatio;
    float nearPlane = camera->getNearPlane();
    float farPlane = camera->getFarPlane();
    return Matrix_Perspective(field_of_view, screenRatio, nearPlane, farPlane);
}