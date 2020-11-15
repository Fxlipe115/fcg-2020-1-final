#include "mouseparameters.h"

MouseParameters::MouseParameters() {
    leftButtonPressed = false;
    rightButtonPressed = false;
    middleButtonPressed = false;
    lastCursorPositionX = 0.0;
    lastCursorPositionY = 0.0;
    rotationAnglePhi = 0.0;
    rotationAngleTheta = 0.0;
    wheelOffset = 0.0;
}