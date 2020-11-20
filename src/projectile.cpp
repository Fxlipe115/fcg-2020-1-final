#include "projectile.h"
#include "matrices.h"

Projectile::Projectile(ObjectInstance* projectile, int damage, BezierCurve* bezierpath)
 : projectile(projectile), bezierpath(bezierpath), damage(damage), traveledDistance(0.0)
{
   position = bezierpath->getA();
}

void Projectile::move(float speed) {
    glm::vec3 curveDirection = bezierpath->getD() - bezierpath->getA();
    float curveDistance = norm(curveDirection);
    traveledDistance += speed;

    float deltaT = traveledDistance / curveDistance;
    deltaT = (deltaT > 1.0) ? 1.0 : deltaT;
    position = bezierpath->getPointAt(deltaT);
}

glm::vec3 Projectile::getPosition(){
    return position;
}