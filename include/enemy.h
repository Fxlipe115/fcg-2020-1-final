#ifndef _ENEMY_H
#define _ENEMY_H

#include <list>

#include "actor.h"
#include "projectile.h"

class Enemy {
    protected:
        Actor* enemy;
        ObjectModel* projectileModel;
    public:
        Enemy(Actor* enemy, ObjectModel* projectileModel);
        virtual std::list<Projectile*> attack(Actor* other) = 0;
        void testCollision(std::list<Projectile*>& projectiles);
        Actor* getActor();
};

#endif