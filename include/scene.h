#ifndef _SCENE_H
#define _SCENE_H

#include <list>

#include "actor.h"
#include "wave.h"
#include "projectile.h"
#include "scenery.h"

struct Scene {
    Scene();
    Actor* player;
    Wave* wave;
    std::list<Projectile*> playerProjectiles;
    std::list<Projectile*> enemyProjectiles;
    Scenery* scenery;
};


#endif