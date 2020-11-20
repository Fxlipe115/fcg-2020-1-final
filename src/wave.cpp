#include "wave.h"

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

int Wave::size() {
    return enemies.size();
}