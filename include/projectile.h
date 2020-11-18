#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "objectinstance.h"

class Projectile {
    private:
        ObjectInstance* projectile;
        int damage;
    public:
        Projectile(ObjectInstance* projectile, int damage);
};

#endif