#ifndef _MOUSE_H
#define _MOUSE_H

class Mouse {
    private:
        Mouse();
        static Mouse* instance;
    public:
        static Mouse* getInstance();
        bool leftButtonPressed;
        bool rightButtonPressed;
        bool middleButtonPressed;
        double lastCursorPositionX;
        double lastCursorPositionY;
};

#endif