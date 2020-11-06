#include "camera.h"

Camera* Camera::instance = nullptr;

Camera* Camera::getInstance() {
    if(instance == nullptr) {
        instance = new Camera();
    }
    return instance;
}

Camera::Camera() {
    theta = 0.0f;
    phi = 0.0f;
    distance = 3.5f;
}