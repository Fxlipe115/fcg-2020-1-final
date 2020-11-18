#ifndef _ACTOR_H
#define _ACTOR_H

#include <glm/vec3.hpp>

#include "objectinstance.h"

class Actor {
    protected:
        ObjectInstance* actor;
        int healthPoints;
    public:
        Actor(ObjectInstance* actor, int healthpoints);
        ObjectInstance* getObjectInstance();
        void/*Attack*/ attack();
        void/*Attack*/ attack(glm::vec3 targetPosition);
        void receiveDamage(int damage);
        bool isAlive();
};

#endif