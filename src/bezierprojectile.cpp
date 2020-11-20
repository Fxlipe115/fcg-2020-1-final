#include "bezierprojectile.h"

#include "matrices.h"

BezierProjectile::BezierProjectile(ObjectInstance* projectile, BezierCurve* bezierpath, int damage) 
 : Projectile(projectile, damage), bezierpath(bezierpath), traveledDistance(0.0)
{
    position = bezierpath->getA();
}

void BezierProjectile::move(float speed) {
    glm::vec3 curveDirection = bezierpath->getD() - bezierpath->getA();
    float curveDistance = norm(curveDirection);
    traveledDistance += speed;

    float deltaT = traveledDistance / curveDistance;
    deltaT = (deltaT > 1.0) ? 1.0 : deltaT;
    position = bezierpath->getPointAt(deltaT);
}