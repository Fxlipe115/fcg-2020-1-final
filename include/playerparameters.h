#ifndef _PLAYERPARAMETERS_H
#define _PLAYERPARAMETERS_H

#include "glm/vec4.hpp"

#include "coordinates.h"

struct PlayerParameters {
    Coordinates rotation;
    Coordinates position;
};

#endif