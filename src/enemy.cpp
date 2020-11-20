#include "enemy.h"

#include "axisalignedboundingbox.h"
#include "collision.h"
#include "sphere.h"

Enemy::Enemy(Actor* enemy, ObjectModel* projectileModel)
 : enemy(enemy), projectileModel(projectileModel)
{
}

void Enemy::testCollision(std::list<Projectile*>& projectiles) {
    for(Projectile*& bullet : projectiles) {
        AxisAlignedBoundingBox enemyBB(enemy->getObjectInstance());
        Sphere bulletBB(bullet->getObjectInstance());
        Collision collision;
        if(collision.collision(enemyBB, bulletBB)) {
            bullet->setOutOfBounds(true);
            enemy->receiveDamage(bullet->getDamage());
        }
    }
}

Actor* Enemy::getActor() {
    return enemy;
}