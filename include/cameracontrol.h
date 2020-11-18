#ifndef _CAMERACONTROL_H
#define _CAMERACONTROL_H

#include "camera.h"
#include "objectinstance.h"
#include "mouseparameters.h"

class CameraControl {
    private:
        Camera* camera;
        ObjectInstance* player;
        MouseParameters* mouse;
        void updateCameraPosition();
        void updateCameraOrientation();
    public:
        CameraControl(Camera* camera, ObjectInstance* player, MouseParameters* mouse);
        void updateCamera();
};

#endif