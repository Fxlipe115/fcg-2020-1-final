#ifndef _MOUSEPARAMETERS_H
#define _MOUSEPARAMETERS_H

struct MouseParameters {
    MouseParameters();
    bool leftButtonPressed;
    bool rightButtonPressed;
    bool middleButtonPressed;
    double lastCursorPositionX;
    double lastCursorPositionY;
    float rotationAngleTheta;
    float rotationAnglePhi;
    float wheelOffset;
};

#endif