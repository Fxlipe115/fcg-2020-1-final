#ifndef _BEZIERPROJECTILE_H
#define _BEZIERPROJECTILE_H

#include "projectile.h"

#include <glm/vec3.hpp>

#include "objectinstance.h"
#include "beziercurve.h"

class BezierProjectile : public Projectile {
    private:
        BezierCurve* bezierpath;
        float traveledDistance;
    public:
        BezierProjectile(ObjectInstance* projectile, BezierCurve* bezierpath, int damage);
        void move(float speed) override;
};

#endif