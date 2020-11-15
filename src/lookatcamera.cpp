#include "lookatcamera.h"

LookAtCamera::LookAtCamera(CameraParameters* cameraParameters)
 : Camera(cameraParameters)
{
}

bool LookAtCamera::isFreeCamera() {
    return false;
}

void LookAtCamera::moveFront(float speed) {
    
}

void LookAtCamera::moveBack(float speed) {

}

void LookAtCamera::moveLeft(float speed) {

}

void LookAtCamera::moveRight(float speed) {

}

void LookAtCamera::moveUp(float speed) {

}

void LookAtCamera::moveDown(float speed) {

}