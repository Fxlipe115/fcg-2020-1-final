#include "gamewindow.h"

GameWindow* GameWindow::instance = nullptr;

GameWindow* GameWindow::getInstance() {
    if(instance == nullptr) {
        instance = new GameWindow();
    }
    return instance;
}

GameWindow::GameWindow() {
    screenRatio = 1.0f;
}

float GameWindow::getScreenRatio() {
    return screenRatio;
}


void GameWindow::setScreenRatio(float screenRatio) {
    screenRatio = screenRatio;
}