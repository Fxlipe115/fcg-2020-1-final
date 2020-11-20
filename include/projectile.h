#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <glm/vec3.hpp>

#include "objectinstance.h"
#include "beziercurve.h"

class Projectile {
    private:
        ObjectInstance* projectile;
        BezierCurve* bezierpath;
        glm::vec3 position;
        int damage;
        float traveledDistance;
    public:
        Projectile(ObjectInstance* projectile, int damage, BezierCurve* bezierpath);
        void move(float speed);
        glm::vec3 getPosition();
};

#endif