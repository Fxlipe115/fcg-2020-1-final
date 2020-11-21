#ifndef _BATTLESHIP_H
#define _BATTLESHIP_H

#include "enemy.h"

class Battleship : public Enemy {
    public:
        Battleship(Actor* enemy, ObjectModel* projectileModel);
        void attack(Actor* other, std::list<Projectile*>& bullets) override;
};

#endif