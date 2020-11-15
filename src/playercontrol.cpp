#include "playercontrol.h"

#include <glm/vec4.hpp>

#include "matrices.h"

PlayerControl::PlayerControl(ObjectInstance* player, KeyboardParameters* keyboard, MouseParameters* mouse)
 : player(player), keyboard(keyboard), mouse(mouse)
{
}

void PlayerControl::updatePlayerPosition() {
    glm::vec4 playerPosition = glm::vec4(player->getTranslation(),1.0f);
    glm::vec4 playerOrientationVector = player->getFrontVector();
    glm::vec4 upVector   = glm::vec4(0.0f,1.0f,0.0f,0.0f);

    float speed = 0.1f;
    glm::vec4 vector_w = playerOrientationVector / norm(playerOrientationVector);
    glm::vec4 vector_u = crossproduct(upVector, vector_w) / norm(crossproduct(upVector, vector_w));
    if(keyboard->upKeyPressed){
        playerPosition += vector_w * speed;
    }
    if(keyboard->downKeyPressed){
        playerPosition -= vector_w * speed;
    }
    if(keyboard->leftKeyPressed){
        playerPosition += vector_u * speed;
    }
    if(keyboard->rightKeyPressed){
        playerPosition -= vector_u * speed;
    }
    player->setTranslation(glm::vec3(playerPosition));
}

void PlayerControl::updatePlayerOrientation() {
    player->setRotation({0.0, mouse->rotationAngleTheta+M_PI,0.0});
}