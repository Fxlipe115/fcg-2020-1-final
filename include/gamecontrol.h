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
#include "shaders.h"
#include "virtualscene.h"
#include "windowparameters.h"

class GameControl
{
private:
    bool usePerspectiveProjection;
    bool useFreeCamera;
    bool showInfoText;
    Shaders* shaders;
    GpuProgram* gpuProgram;
    VirtualScene* virtualScene;
    Camera* camera;
    Projection* projection;
    WindowParameters* windowParameters;
    MouseParameters* mouseParameters;
    KeyboardParameters* keyboardParameters;
    ObjectModel* shipModel;
    ObjectModel* planeModel;
    ObjectModel* playerModel;
    ObjectInstance* player;
public:
    GameControl();
    ~GameControl();
    void updateGameState();
};

#endif