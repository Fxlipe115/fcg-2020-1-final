#include "gamecontrol.h"

#include <cstdlib>

#include "bezierprojectile.h"
#include "linearprojectile.h"
#include "beziercurve.h"
#include "collision.h"
#include "textrendering.h"
#include "battleship.h"

GameControl::GameControl()
 : usePerspectiveProjection(true), useFreeCamera(false),
   showInfoText(true), camera(nullptr), projection(nullptr), 
   currentWave(0), gameOver(false), lastAttackTime(glfwGetTime())
{
    srand(time(NULL));

    shaders = new Shaders("./src/shaders/shader_fragment.glsl", "./src/shaders/shader_vertex.glsl");
    gpuProgram = new GpuProgram(shaders);
    virtualScene = new VirtualScene();
    textures = new Textures();
    textures->loadTextureImage("./data/A_Kuznetsov.tga");
    textures->loadTextureImage("./data/A_Kuznetsov2.tga");
    textures->loadTextureImage("./data/water.jpg");

    windowParameters = new WindowParameters();
    mouseParameters = new MouseParameters();
    keyboardParameters = new KeyboardParameters();

    Callbacks* callbacks = Callbacks::getInstance();
    callbacks->setWindowParameters(windowParameters);
    callbacks->setMouseParameters(mouseParameters);
    callbacks->setKeyboardParameters(keyboardParameters);

    scene.scenery = new Scenery(glm::vec3(100.0, 0.0, 100.0), virtualScene);
    
    bulletModel = new ObjectModel("./data/sphere.obj");
    bulletModel->buildTrianglesAndAddToVirtualScene(virtualScene);

    playerModel = new ObjectModel("./data/Shrek.obj");
    playerModel->buildTrianglesAndAddToVirtualScene(virtualScene);
    playerObject = new ObjectInstance(playerModel);
    playerObject->setScale({0.01f, 0.01f, 0.01f});
    playerObject->setTranslation({0.0, 0.6, 50.0});
    scene.player = new Player(new Actor(playerObject, 2000), bulletModel);

    shipModel = new ObjectModel("./data/kuznetsov.obj");
    shipModel->buildTrianglesAndAddToVirtualScene(virtualScene);
    std::list<Enemy*> wave0list;
    for(int i = 0; i < 5; i++) {    
        ObjectInstance* ship = new ObjectInstance(shipModel);
        ship->setTranslation({-40.0f+i*20, -0.05f, (i%2)*-50.0f});
        ship->setScale({4.0, 4.0, 4.0});
        ship->setRotation({-1.57, 0.0, 0.0});

        Enemy* enemy = new Battleship(new Actor(ship, 10000), bulletModel);

        wave0list.push_back(enemy);
    }

    waves.push_back(Wave(wave0list));


    ObjectInstance* arcbullet = new ObjectInstance(bulletModel);
    BezierCurve* trajectory = new BezierCurve({0.0, 0.0, 0.0}, {10.0, 5.0, 0.0}, {20.0, 5.0, 0.0}, {30.0, 0.0, 0.0});
    scene.enemyProjectiles.push_back(new BezierProjectile(arcbullet, trajectory, 10));

    ObjectInstance* linearbullet = new ObjectInstance(bulletModel);
    scene.enemyProjectiles.push_back(new LinearProjectile(linearbullet, 10, {0.0, 1.0, 0.0}, {0.0, 0.0, -1.0}));

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
    delete scene.player;
}

void GameControl::updateGameState(GLFWwindow* window) {
    gpuProgram->use();

    delete camera;
    if(useFreeCamera) {
        camera = new FreeCamera();
    } else {
        camera = new LookAtCamera();
    }

    if(currentWave < waves.size()) {
        scene.wave = &waves[currentWave];
    } else {
        gameOver = true;
    }

    if(!scene.player->getActor()->isAlive()) {
        gameOver = true;
    }

    if(!gameOver){
        PlayerControl playerControl(&scene, keyboardParameters, mouseParameters);
        playerControl.updatePlayer();

        float lineheight = TextRendering_LineHeight(window);
        float charwidth = TextRendering_CharWidth(window);
        char buffer[20];
        int numchars = snprintf(buffer, 20, "Health %d", scene.player->getActor()->getHealthPoints());
        TextRendering_PrintString(window, buffer, 1.0f-(numchars + 30)*charwidth, 1.0f-lineheight, 1.0f);
    } else {
        float lineheight = TextRendering_LineHeight(window);
        float charwidth = TextRendering_CharWidth(window);
        TextRendering_PrintString(window, "Game Over", 1.0f-(10 + 30)*charwidth, 1.0f-lineheight, 1.0f);
    }
    CameraControl cameraControl(camera, playerObject, mouseParameters);
    cameraControl.updateCamera();

    gpuProgram->use();

    delete projection;
    if (usePerspectiveProjection) {
        projection = new PerspectiveProjection(camera, windowParameters);
    } else {
        projection = new OrthographicProjection(camera, windowParameters);
    }

    double now = glfwGetTime();
    if(now - lastAttackTime > 0.01) {
        lastAttackTime = now;
        for(Enemy*& enemy : scene.wave->getEnemies()) {
            if((rand()%100) < 1){
                enemy->attack(scene.player->getActor(), scene.enemyProjectiles);
            }
        }
    }

    scene.wave->checkCollisions(scene.playerProjectiles);

    for(Projectile* projectile : scene.enemyProjectiles) {
        projectile->move(0.6);
        projectile->getObjectInstance()->draw(gpuProgram,ShaderFlags::BULLET);
        Sphere boundingSphere(projectile->getObjectInstance());
        for(Plane& wall : scene.scenery->getWalls()) {
            if(wall.distanceToPlane(boundingSphere.getCenter()) > 0) {
                projectile->setOutOfBounds(true);
            }
        }
    }
    for(Projectile* projectile : scene.playerProjectiles) {
        projectile->move(1.0);
        projectile->getObjectInstance()->draw(gpuProgram,ShaderFlags::BULLET);
        Sphere boundingSphere(projectile->getObjectInstance());
        for(Plane& wall : scene.scenery->getWalls()) {
            if(wall.distanceToPlane(boundingSphere.getCenter()) > 0) {
                projectile->setOutOfBounds(true);
            }
        }
    }

    scene.enemyProjectiles.remove_if([](Projectile*& projectile) {
        return projectile->isOutOfBounds();
    });
    scene.playerProjectiles.remove_if([](Projectile*& projectile) {
        return projectile->isOutOfBounds();
    });

    for(SwitchKeys key : keyboardParameters->pressedSwitches) {
        switch (key) {
        case SwitchKeys::R_SWITCH_KEY:
            shaders->reload();
            delete gpuProgram;
            gpuProgram = new GpuProgram(shaders);
            fprintf(stdout,"Shaders recarregados!\n");
            fflush(stdout);
            break;

        case SwitchKeys::C_SWITCH_KEY:
            useFreeCamera = !useFreeCamera;
            break;

        case SwitchKeys::P_SWITCH_KEY:
            usePerspectiveProjection = !usePerspectiveProjection;
            break;

        case SwitchKeys::SPACE_SWITCH_KEY:
            scene.player->attack(scene.playerProjectiles);
            break;

        default:
            break;
        }
    }
    keyboardParameters->pressedSwitches.clear();

    gpuProgram->sendViewMatrixToGPU(camera->getViewMatrix());
    gpuProgram->sendProjectionMatrixToGPU(projection->generateMatrix());

    if(scene.player->getActor()->isAlive()) {
        playerObject->draw(gpuProgram, ShaderFlags::PLAYER);
    }

    if(!gameOver) {
        waves.at(currentWave).removeDeadEnemies();
        waves.at(currentWave).drawEnemies(gpuProgram);
        if(waves.at(currentWave).size() < 1) {
            currentWave++;
        }
    }
    
    if(currentWave >= waves.size()) {
        gameOver = true;
    }

    scene.scenery->draw(gpuProgram);
}