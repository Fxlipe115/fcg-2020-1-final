#ifndef _WAVE_H
#define _WAVE_H

#include <list>

#include "actor.h"
#include "gpuprogram.h"

class Wave {
    private:
        std::list<Actor> enemies;
    public:
        Wave(std::list<Actor>& enemies);
        void drawEnemies(GpuProgram* gpuProgram);
        std::list<Actor>& getEnemies();
        void removeDeadEnemies();
        int size();
};

#endif