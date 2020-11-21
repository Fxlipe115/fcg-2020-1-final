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
        virtual void attack(Actor* other, std::list<Projectile*>& bullets) = 0;
        void testCollision(std::list<Projectile*>& projectiles);
        Actor* getActor();
};

#endif