#include "playercontrol.h"

#include <glm/vec4.hpp>
#include <GLFW/glfw3.h>

#include "collision.h"
#include "matrices.h"
#include "objectinstance.h"

PlayerControl::PlayerControl(Scene* scene, KeyboardParameters* keyboard, MouseParameters* mouse)
 : scene(scene), keyboard(keyboard), mouse(mouse)
{
    lastUpdateTime = glfwGetTime();
}

void PlayerControl::updatePlayerPosition() {
    double time = glfwGetTime();
    float timeSinceLastUpdate = (time - lastUpdateTime);

    ObjectInstance* playerObject = scene->player->getObjectInstance();

    glm::vec4 playerPosition = glm::vec4(playerObject->getTranslation(),1.0f);
    glm::vec4 playerOrientationVector = playerObject->getFrontVector();
    glm::vec4 upVector   = glm::vec4(0.0f,1.0f,0.0f,0.0f);

    float speed = 0.05f * 1000000;
    glm::vec4 vector_w = playerOrientationVector / norm(playerOrientationVector);
    glm::vec4 vector_u = crossproduct(upVector, vector_w) / norm(crossproduct(upVector, vector_w));
    
    glm::vec4 movementVector = {0.0, 0.0, 0.0, 0.0};

    if(keyboard->upKeyPressed){
        movementVector = movementVector + vector_w * speed * timeSinceLastUpdate;
    }
    if(keyboard->downKeyPressed){
        movementVector = movementVector - vector_w * speed * timeSinceLastUpdate;
    }
    if(keyboard->leftKeyPressed){
        movementVector = movementVector + vector_u * speed * timeSinceLastUpdate;
    }
    if(keyboard->rightKeyPressed){
        movementVector = movementVector - vector_u * speed * timeSinceLastUpdate;
    }

    
    /* 
     * This treatment of collision is better because the player can slide
     * on the surface with which it collided, but it depends on having the
     * normal of the collision, which currently is not possible on axis
     * aligned bounding boxes.
     */
    // glm::vec4 collisionNormalVector = calculateCollisionNormalVector();
    // float speedIntoCollision = -dotproduct(movementVector, collisionNormalVector);
    // float speedSlack = 0.5;
    // playerPosition += movementVector + collisionNormalVector * (speedIntoCollision-speedSlack);
    // player->setTranslation(glm::vec3(playerPosition));

    glm::vec3 nextPlayerPosition = playerPosition + movementVector;
    playerObject->setTranslation(glm::vec3(nextPlayerPosition));

    bool willCollide = false;
    for(Actor& enemy : scene->wave->getEnemies()) {
        AxisAlignedBoundingBox playerBB(playerObject);
        AxisAlignedBoundingBox enemyBB(enemy.getObjectInstance());
        Collision collision;
        if(collision.collision(playerBB, enemyBB)) {
            scene->player->receiveDamage(10);
            enemy.receiveDamage(100);
            willCollide = true;
        }
    }
    for(Plane& wall : scene->scenery->getWalls()) {
        Sphere playerBoundingBox(playerObject);
        Collision collision;
        if(collision.collision(playerBoundingBox, wall)) {
            willCollide = true;
        }
    }

    for(Projectile*& bullet : scene->projectiles) {
        AxisAlignedBoundingBox playerBoundingBox(playerObject);
        Sphere bulletBoundingBox(bullet->getObjectInstance());
        Collision collision;
        if(collision.collision(playerBoundingBox, bulletBoundingBox)) {
            willCollide = true;
        }
    }
    
    if(willCollide) {
        playerObject->setTranslation(glm::vec3(playerPosition));
    }
    
    lastUpdateTime = time;
}

void PlayerControl::updatePlayerOrientation() {
    scene->player->getObjectInstance()->setRotation({0.0, mouse->rotationAngleTheta+M_PI,0.0});
}

void PlayerControl::updatePlayer() {
    updatePlayerOrientation();
    updatePlayerPosition();
}

glm::vec4 PlayerControl::calculateCollisionNormalVector() {
    glm::vec3 collisionNormalVector = {0.0, 0.0, 0.0};
    for(Plane& wall : scene->scenery->getWalls()) {
        Sphere playerBoundingBox(scene->player->getObjectInstance());
        Collision collision;
        if(collision.collision(playerBoundingBox, wall)) {
            collisionNormalVector = collisionNormalVector + collision.getDirectionOfCollision();
        }
    }
    return glm::vec4(collisionNormalVector, 0.0);
}