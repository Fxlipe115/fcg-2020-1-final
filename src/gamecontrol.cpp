#include "gamecontrol.h"

GameControl::GameControl()
 : usePerspectiveProjection(true), useFreeCamera(false),
   showInfoText(true), camera(nullptr), projection(nullptr), 
   currentWave(0), gameOver(false)
{
    shaders = new Shaders("./src/shaders/shader_fragment.glsl", "./src/shaders/shader_vertex.glsl");
    gpuProgram = new GpuProgram(shaders);
    virtualScene = new VirtualScene();
    textures = new Textures();
    textures->loadTextureImage("./data/aircraftdeck.jpg");

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

    
    std::list<Actor> wave0list;
    for(int i = 0; i < 5; i++) {    
        ObjectInstance* ship = new ObjectInstance(shipModel);
        ship->setTranslation({-1.0f+i*4, -0.05f, (i%2)*2.0f});
        ship->setScale({1.0, 1.0, 1.0});
        ship->setRotation({-1.57, 0.0, 0.0});

        wave0list.push_back(Actor(ship, 200));
    }

    waves.push_back(Wave(wave0list));
}

GameControl::~GameControl() {
    delete shaders;
    delete gpuProgram;
    delete virtualScene;
    delete camera;
    delete projection;
    delete windowParameters;
    delete mouseParameters;
    delete keyboardParameters;
    delete playerModel;
    delete player;
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
    playerControl.updatePlayer();

    CameraControl cameraControl(camera, player, mouseParameters);
    cameraControl.updateCamera();

    delete projection;
    if (usePerspectiveProjection) {
        projection = new PerspectiveProjection(camera, windowParameters);
    } else {
        projection = new OrthographicProjection(camera, windowParameters);
    }

    gpuProgram->sendViewMatrixToGPU(camera->getViewMatrix());
    gpuProgram->sendProjectionMatrixToGPU(projection->generateMatrix());

    waves.at(currentWave).drawEnemies(gpuProgram);

    player->draw(gpuProgram, ShaderFlags::BUNNY);

    ObjectInstance plane(planeModel);
    plane.setTranslation({0.0f, 0.0f, 0.0f});
    plane.setScale({2.0f, 1.0f, 2.0f});
    plane.draw(gpuProgram, ShaderFlags::PLANE);

    waves.at(currentWave).removeDeadEnemies();
    if(waves.at(currentWave).size() < 1) {
        currentWave++;
    }
    if(currentWave >= waves.size()) {
        gameOver = true;
    }
}