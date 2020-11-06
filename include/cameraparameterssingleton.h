#ifndef _CAMERAPARAMETERSSINGLETON_H
#define _CAMERAPARAMETERSSINGLETON_H

#include "cameraparameters.h"

class CameraParametersSingleton : public CameraParameters
{
    private:
        CameraParametersSingleton();
        static CameraParametersSingleton* instance;

    public:
        static CameraParametersSingleton* getInstance();
};

#endif