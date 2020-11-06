#include "cameraparameterssingleton.h"

CameraParametersSingleton* CameraParametersSingleton::instance = nullptr;

CameraParametersSingleton* CameraParametersSingleton::getInstance() {
    if(instance == nullptr) {
        instance = new CameraParametersSingleton();
    }
    return instance;
}

CameraParametersSingleton::CameraParametersSingleton()
 : CameraParameters()
{
}