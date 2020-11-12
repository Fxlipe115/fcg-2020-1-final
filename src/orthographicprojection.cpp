#include "orthographicprojection.h"

#include "matrices.h"

OrthographicProjection::OrthographicProjection(Camera* camera, WindowParameters* windowParameters)
 : Projection(camera, windowParameters)
{
}

glm::mat4 OrthographicProjection::generateMatrix() {
    float screenRatio = windowParameters->screenRatio;
    float nearPlane = camera->getParameters()->nearPlane;
    float farPlane = camera->getParameters()->farPlane;
    float distance = camera->getParameters()->distance;
    float t = 1.5f*distance/2.5f;
    float b = -t;
    float r = t*screenRatio;
    float l = -r;
    return Matrix_Orthographic(l, r, b, t, nearPlane, farPlane);
}