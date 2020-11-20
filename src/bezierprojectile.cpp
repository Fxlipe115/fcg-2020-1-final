#include "bezierprojectile.h"

#include "matrices.h"

BezierProjectile::BezierProjectile(ObjectInstance* projectile, BezierCurve* bezierpath, int damage) 
 : Projectile(projectile, damage), bezierpath(bezierpath), traveledDistance(0.0)
{
    position = bezierpath->getA();
    projectile->setTranslation(position);
}

void BezierProjectile::move(float speed) {
    glm::vec3 curveDirection = bezierpath->getD() - bezierpath->getA();
    float curveDistance = norm(curveDirection);
    traveledDistance += speed;

    float deltaT = traveledDistance / curveDistance;

    if(deltaT > 1.0) {
        deltaT = 1.0;
        outOfBounds = true;
    }
    position = bezierpath->getPointAt(deltaT);

    projectile->setTranslation(position);

    if(projectile->getTranslation().y < -5.0) {
        outOfBounds = true;
    }
}