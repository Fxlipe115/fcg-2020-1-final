#ifndef _WAVE_H
#define _WAVE_H

#include <list>

#include "enemy.h"
#include "gpuprogram.h"

class Wave {
    private:
        std::list<Enemy*> enemies;
    public:
        Wave(std::list<Enemy*>& enemies);
        void drawEnemies(GpuProgram* gpuProgram);
        std::list<Enemy*>& getEnemies();
        void removeDeadEnemies();
        void checkCollisions(std::list<Projectile*> bullets);
        int size();
};

#endif