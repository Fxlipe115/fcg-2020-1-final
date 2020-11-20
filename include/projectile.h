#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <glm/vec3.hpp>

#include "objectinstance.h"
#include "beziercurve.h"

class Projectile {
    protected:
        ObjectInstance* projectile;
        glm::vec3 position;
        int damage;
        glm::vec3 direction;
        float traveledDistance;
    public:
        Projectile(ObjectInstance* projectile, int damage);
        Projectile(ObjectInstance* projectile, int damage, glm::vec3 initialPosition, glm::vec3 direction);
        virtual void move(float speed) = 0;
        ObjectInstance* getObjectInstance();
        glm::vec3 getPosition();
        int getDamage();
};

#endif