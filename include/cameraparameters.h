#ifndef _CAMERAPARAMETERS_H
#define _CAMERAPARAMETERS_H

class CameraParameters
{
    public:
        CameraParameters();
        float theta;
        float phi;
        float distance;
        float nearPlane;
        float farPlane;
};

#endif