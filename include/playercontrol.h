#ifndef _PLAYERCONTROL_H
#define _PLAYERCONTROL_H

#include "objectinstance.h"
#include "keyboardparameters.h"
#include "mouseparameters.h"

class PlayerControl {
    private:
        ObjectInstance* player;
        KeyboardParameters* keyboard;
        MouseParameters* mouse;
    public:
        PlayerControl(ObjectInstance* player, KeyboardParameters* keyboard, MouseParameters* mouse);
        void updatePlayerPosition();
        void updatePlayerOrientation();
};

#endif