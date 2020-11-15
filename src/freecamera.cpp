#include "freecamera.h"

#include "matrices.h"

FreeCamera::FreeCamera()
 : Camera()
{
}

glm::vec4 FreeCamera::getViewVector() {
    glm::vec4 viewVector = glm::vec4(0.0, 0.0, 1.0, 0.0)
                    * Matrix_Rotate_X(-phi)
                    * Matrix_Rotate_Y(M_PI-theta);

    return viewVector/norm(viewVector);
}

bool FreeCamera::isFreeCamera() {
    return true;
}