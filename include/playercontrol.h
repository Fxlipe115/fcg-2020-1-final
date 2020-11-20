#ifndef _PLAYERCONTROL_H
#define _PLAYERCONTROL_H

#include "objectinstance.h"
#include "keyboardparameters.h"
#include "mouseparameters.h"
#include "scenery.h"

class PlayerControl {
    private:
        ObjectInstance* player;
        KeyboardParameters* keyboard;
        MouseParameters* mouse;
        Scenery* scenery;
        void updatePlayerPosition();
        void updatePlayerOrientation();
        glm::vec4 calculateCollisionNormalVector();
        double lastUpdateTime;
    public:
        PlayerControl(ObjectInstance* player, KeyboardParameters* keyboard, MouseParameters* mouse, Scenery* scenery);
        void updatePlayer();
};

#endif