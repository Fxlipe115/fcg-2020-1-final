#include "projectile.h"

Projectile::Projectile(ObjectInstance* projectile, int damage) 
 : projectile(projectile), damage(damage)
{
    
}

glm::vec3 Projectile::getPosition(){
    return position;
}

ObjectInstance* Projectile::getObjectInstance() {
    return projectile;
}

int Projectile::getDamage() {
    return damage;
}