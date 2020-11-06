#include "mouse.h"

Mouse* Mouse::instance = nullptr;

Mouse* Mouse::getInstance() {
    if(instance == nullptr) {
        instance = new Mouse();
    }
    return instance;
}

Mouse::Mouse() {
    leftButtonPressed = false;
    rightButtonPressed = false;
    middleButtonPressed = false;
    lastCursorPositionX = 0.0;
    lastCursorPositionY = 0.0;
}