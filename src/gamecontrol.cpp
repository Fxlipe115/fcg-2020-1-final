#include "gamecontrol.h"

GameControl::GameControl()
 : usePerspectiveProjection(true), showInfoText(true), 
   camera(nullptr), projection(nullptr)
{
    shaders = new Shaders("./src/shaders/shader_fragment.glsl", "./src/shaders/shader_vertex.glsl");
    gpuProgram = new GpuProgram(shaders);
    virtualScene = new VirtualScene();

    windowParameters = new WindowParameters();
    mouseParameters = new MouseParameters();
    keyboardParameters = new KeyboardParameters();

    Callbacks* callbacks = Callbacks::getInstance();
    callbacks->setWindowParameters(windowParameters);
    callbacks->setMouseParameters(mouseParameters);
    callbacks->setKeyboardParameters(keyboardParameters);

    shipModel = new ObjectModel("./data/kuznetsov.obj");
    shipModel->buildTrianglesAndAddToVirtualScene(virtualScene);

    planeModel = new ObjectModel("./data/plane.obj");
    planeModel->buildTrianglesAndAddToVirtualScene(virtualScene);


    playerModel = new ObjectModel("./data/Shrek.obj");
    playerModel->buildTrianglesAndAddToVirtualScene(virtualScene);
    player = new ObjectInstance(playerModel);
    player->setScale({0.01f, 0.01f, 0.01f});
    player->setTranslation({0.0, 0.7, 0.0});
}

void GameControl::updateGameState() {
    gpuProgram->use();

    delete camera;
    if(useFreeCamera) {
        camera = new FreeCamera();
    } else {
        camera = new LookAtCamera();
    }

    PlayerControl playerControl(player, keyboardParameters, mouseParameters);
    playerControl.updatePlayerPosition();
    playerControl.updatePlayerOrientation();

    CameraControl cameraControl(camera, player, mouseParameters);
    cameraControl.updateCameraPosition();
    cameraControl.updateCameraOrientation();

    if (usePerspectiveProjection) {
        projection = new PerspectiveProjection(camera, windowParameters);
    } else {
        projection = new OrthographicProjection(camera, windowParameters);
    }

    gpuProgram->sendViewMatrixToGPU(camera->getViewMatrix());
    gpuProgram->sendProjectionMatrixToGPU(projection->generateMatrix());

    ObjectInstance ship(shipModel);
    ship.setTranslation({-1.0f, -0.05f, 0.0f});
    ship.setScale({0.5, 0.5, 0.5});
    ship.setRotation({-1.57, 0.0, 0.0});
    ship.draw(gpuProgram, ShaderFlags::SPHERE);

    player->draw(gpuProgram, ShaderFlags::BUNNY);

    ObjectInstance plane(planeModel);
    plane.setTranslation({0.0f, 0.0f, 0.0f});
    plane.setScale({2.0f, 1.0f, 2.0f});
    plane.draw(gpuProgram, ShaderFlags::PLANE);
}