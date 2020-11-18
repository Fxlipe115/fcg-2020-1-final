#include "wave.h"

Wave::Wave(std::list<Actor>& enemies)
 : enemies(enemies)
{
}

void Wave::drawEnemies(GpuProgram* gpuProgram) {
    for(Actor enemy : enemies) {
        enemy.getObjectInstance()->draw(gpuProgram, ShaderFlags::CARRIER);
    }
}

void Wave::removeDeadEnemies() {
    enemies.remove_if([](Actor& enemy) {
        return !enemy.isAlive();
    });
}

int Wave::size() {
    return enemies.size();
}