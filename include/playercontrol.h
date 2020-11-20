#ifndef _PLAYERCONTROL_H
#define _PLAYERCONTROL_H

#include "keyboardparameters.h"
#include "mouseparameters.h"
#include "scene.h"

class PlayerControl {
    private:
        Scene* scene;
        KeyboardParameters* keyboard;
        MouseParameters* mouse;
        void updatePlayerPosition();
        void updatePlayerOrientation();
        glm::vec4 calculateCollisionNormalVector();
        double lastUpdateTime;
    public:
        PlayerControl(Scene* scene, KeyboardParameters* keyboard, MouseParameters* mouse);
        void updatePlayer();
};

#endif