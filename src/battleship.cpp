#include "battleship.h"

#include "bezierprojectile.h"
#include "beziercurve.h"
#include "matrices.h"

Battleship::Battleship(Actor* enemy, ObjectModel* projectileModel)
 : Enemy(enemy, projectileModel)
{
}

void Battleship::attack(Actor* other, std::list<Projectile*>& bullets) {
    glm::vec3 a = enemy->getObjectInstance()->getTranslation();
    glm::vec3 d = other->getObjectInstance()->getTranslation();

    glm::vec3 direction = d - a;
    float distance = norm(direction);
    direction = direction / norm(direction);

    glm::vec3 b = a + direction * (distance * 1/3);
    glm::vec3 c = a + direction * (distance * 2/3);
    b.y = 5.0;
    c.y = 5.0;
    d.y = 0.0;
    BezierCurve* trajectory = new BezierCurve(a, b, c, d);

    ObjectInstance* bulletInstance = new ObjectInstance(projectileModel);
    bulletInstance->setScale({0.3, 0.3, 0.3});
    Projectile* bullet = new BezierProjectile(bulletInstance, trajectory, 300);
    bullets.push_back(bullet);
}
