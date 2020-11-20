#ifndef _GAMECONTROL_H
#define _GAMECONTROL_H

#include "callbacks.h"
#include "camera.h"
#include "cameracontrol.h"
#include "freecamera.h"
#include "gpuprogram.h"
#include "keyboardparameters.h"
#include "lookatcamera.h"
#include "mouseparameters.h"
#include "objectmodel.h"
#include "objectinstance.h"
#include "orthographicprojection.h"
#include "perspectiveprojection.h"
#include "playercontrol.h"
#include "projection.h"
#include "scene.h"
#include "scenery.h"
#include "shaders.h"
#include "textures.h"
#include "virtualscene.h"
#include "windowparameters.h"
#include "wave.h"
#include "projectile.h"
class GameControl {
    private:
        bool usePerspectiveProjection;
        bool useFreeCamera;
        bool showInfoText;
        Shaders* shaders;
        GpuProgram* gpuProgram;
        VirtualScene* virtualScene;
        Textures* textures;
        Camera* camera;
        Projection* projection;
        WindowParameters* windowParameters;
        MouseParameters* mouseParameters;
        KeyboardParameters* keyboardParameters;
        ObjectModel* shipModel;
        ObjectModel* playerModel;
        ObjectModel* bulletModel;
        ObjectInstance* playerObject;
        std::vector<Wave> waves;
        unsigned int currentWave;
        bool gameOver;
        Scene scene;
    public:
        GameControl();
        ~GameControl();
        void updateGameState(GLFWwindow* window);
};

#endif