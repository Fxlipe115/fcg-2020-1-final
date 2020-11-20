#include "linearprojectile.h"

#include "matrices.h"

LinearProjectile::LinearProjectile(ObjectInstance* projectile, int damage, glm::vec3 initialPosition, glm::vec3 direction) 
 : Projectile(projectile, damage), direction(direction)
{
    position = initialPosition;
    direction = direction / norm(direction);
    projectile->setTranslation(position);
}

void LinearProjectile::move(float speed) {
    position = position + direction * speed;
    projectile->setTranslation(position);
}