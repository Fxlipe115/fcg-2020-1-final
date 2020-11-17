#ifndef _KEYBOARDPARAMETERS_H
#define _KEYBOARDPARAMETERS_H

#include <vector>

enum SwitchKeys {
    SPACE_SWITCH_KEY,
    P_SWITCH_KEY,
    C_SWITCH_KEY,
    O_SWITCH_KEY,
    H_SWITCH_KEY,
    R_SWITCH_KEY,
    ESC_SWITCH_KEY
};

struct KeyboardParameters {
    KeyboardParameters();
    bool upKeyPressed;
    bool downKeyPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;
    bool escKeyPressed;
    std::vector<SwitchKeys> pressedSwitches;
};

#endif