#include "playercontrol.h"

#include <glm/vec4.hpp>

#include "collision.h"
#include "matrices.h"
#include "sphere.h"

PlayerControl::PlayerControl(ObjectInstance* player, KeyboardParameters* keyboard, MouseParameters* mouse, Scenery* scenery)
 : player(player), keyboard(keyboard), mouse(mouse), scenery(scenery)
{
}

void PlayerControl::updatePlayerPosition() {
    glm::vec4 playerPosition = glm::vec4(player->getTranslation(),1.0f);
    glm::vec4 playerOrientationVector = player->getFrontVector();
    glm::vec4 upVector   = glm::vec4(0.0f,1.0f,0.0f,0.0f);

    float speed = 0.1f;
    glm::vec4 vector_w = playerOrientationVector / norm(playerOrientationVector);
    glm::vec4 vector_u = crossproduct(upVector, vector_w) / norm(crossproduct(upVector, vector_w));
    
    glm::vec4 movementVector = {0.0, 0.0, 0.0, 0.0};

    if(keyboard->upKeyPressed){
        movementVector = movementVector + vector_w * speed;
    }
    if(keyboard->downKeyPressed){
        movementVector = movementVector - vector_w * speed;
    }
    if(keyboard->leftKeyPressed){
        movementVector = movementVector + vector_u * speed;
    }
    if(keyboard->rightKeyPressed){
        movementVector = movementVector - vector_u * speed;
    }

    glm::vec4 collisionNormalVector = calculateCollisionNormalVector();
    float speedIntoCollision = -dotproduct(movementVector, collisionNormalVector);
    
    float speedSlack = 0.05;
    playerPosition += movementVector + collisionNormalVector * (speedIntoCollision-speedSlack);
    
    player->setTranslation(glm::vec3(playerPosition));
}

void PlayerControl::updatePlayerOrientation() {
    player->setRotation({0.0, mouse->rotationAngleTheta+M_PI,0.0});
}

void PlayerControl::updatePlayer() {
    updatePlayerOrientation();
    updatePlayerPosition();
}

glm::vec4 PlayerControl::calculateCollisionNormalVector() {
    glm::vec3 collisionNormalVector = {0.0, 0.0, 0.0};
    for(Plane& wall : scenery->getWalls()) {
        Sphere playerBoundingBox(player);
        if(Collision::collision(playerBoundingBox, wall)) {
            collisionNormalVector = collisionNormalVector + wall.getNormal();
        }
    }
    return glm::vec4(collisionNormalVector, 0.0);
}