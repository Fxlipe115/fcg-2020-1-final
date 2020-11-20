#ifndef _BATTLESHIP_H
#define _BATTLESHIP_H

#include "enemy.h"

class Battleship : public Enemy {
    public:
        Battleship(Actor* enemy, ObjectModel* projectileModel);
        std::list<Projectile*> attack(Actor* other) override;
};

#endif