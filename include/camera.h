#ifndef _CAMERA_H
#define _CAMERA_H

class Camera
{
    private:
        Camera();
        static Camera* instance;
    public:
        static Camera* getInstance();
        float theta;
        float phi;
        float distance;
};


#endif