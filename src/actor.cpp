#include "actor.h"

#include "linearprojectile.h"

Actor::Actor(ObjectInstance* actor, int healthpoints)
 : actor(actor), healthPoints(healthpoints)
{
}

ObjectInstance* Actor::getObjectInstance() {
    return actor;
}

int Actor::getHealthPoints() {
    return healthPoints;
}

void Actor::receiveDamage(int damage) {
    healthPoints -= damage;
}

bool Actor::isAlive() {
    return healthPoints > 0;
}