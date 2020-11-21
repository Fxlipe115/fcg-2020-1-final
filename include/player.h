#ifndef _PLAYER_H
#define _PLAYER_H

#include <list>

#include "actor.h"
#include "objectmodel.h"
#include "projectile.h"

class Player {
    private:
        Actor* player;
        ObjectModel* projectileModel;
    public:
        Player(Actor* player, ObjectModel* projectileModel);
        void attack(std::list<Projectile*>& bullets);
        Actor* getActor();
};

#endif