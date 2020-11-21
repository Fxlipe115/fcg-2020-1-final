#include "player.h"

#include "linearprojectile.h"

Player::Player(Actor* player, ObjectModel* projectileModel)
 : player(player), projectileModel(projectileModel)
{
}

void Player::attack(std::list<Projectile*>& bullets) {
    glm::vec3 playerPosition = player->getObjectInstance()->getTranslation();
    glm::vec3 facingDirection = player->getObjectInstance()->getFrontVector();
    
    ObjectInstance* bulletInstance = new ObjectInstance(projectileModel);
    bulletInstance->setScale({0.3, 0.3, 0.3});
    Projectile* bullet = new LinearProjectile(bulletInstance, 300, playerPosition, facingDirection);
    bullets.push_back(bullet);
}

Actor* Player::getActor() {
    return player;
}