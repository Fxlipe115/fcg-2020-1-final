#include "wave.h"

#include "collision.h"

Wave::Wave(std::list<Enemy*>& enemies)
 : enemies(enemies)
{
}

void Wave::drawEnemies(GpuProgram* gpuProgram) {
    for(Enemy* enemy : enemies) {
        enemy->getActor()->getObjectInstance()->draw(gpuProgram, ShaderFlags::CARRIER);
    }
}

std::list<Enemy*>& Wave::getEnemies() {
    return enemies;
}

void Wave::removeDeadEnemies() {
    enemies.remove_if([](Enemy*& enemy) {
        return !enemy->getActor()->isAlive();
    });
}

void Wave::checkCollisions(std::list<Projectile*> bullets) {
    for(Enemy*& enemy : enemies) {
        for(Projectile*& bullet : bullets) {
            AxisAlignedBoundingBox enemyBB(enemy->getActor()->getObjectInstance());
            Sphere bulletBB(bullet->getObjectInstance());
            Collision collision;
            if(collision.collision(enemyBB, bulletBB)) {
                enemy->getActor()->receiveDamage(bullet->getDamage());
                bullet->setOutOfBounds(true);
            }
        }
    }
}

int Wave::size() {
    return enemies.size();
}