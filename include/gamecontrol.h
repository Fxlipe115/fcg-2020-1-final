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
    bool usePerspectiveProjection;
    bool useFreeCamera;
    bool showInfoText;
public:
    GameControl();
    void updateGameState();
};

#endif