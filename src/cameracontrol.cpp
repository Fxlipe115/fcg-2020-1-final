#include "cameracontrol.h"

#include <glm/vec4.hpp>

CameraControl::CameraControl(Camera* camera, ObjectInstance* player, MouseParameters* mouse)
 : camera(camera), player(player), mouse(mouse)
{
}

void CameraControl::updateCameraPosition() {
    // This is done to align the camera with the player's model head
    glm::vec4 playerHeadPosition = glm::vec4(player->getTranslation(), 0.1);
    glm::vec4 playerDirection = player->getFrontVector();
    playerHeadPosition.y += 1;
    playerHeadPosition += playerDirection * 0.45f;
    camera->setPosition(playerHeadPosition);
}
void CameraControl::updateCameraOrientation() {
    camera->setPhi(mouse->rotationAnglePhi);
    camera->setTheta(mouse->rotationAngleTheta);
}

void CameraControl::updateCamera() {
    updateCameraOrientation();
    updateCameraPosition();
}