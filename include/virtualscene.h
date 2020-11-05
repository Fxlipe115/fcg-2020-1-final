#ifndef _VIRTUALSCENE_H
#define _VIRTUALSCENE_H

#include <map>
#include <string>

#include "sceneobject.h"

class VirtualScene
{
    private:
        std::map<std::string, SceneObject> scene;
    public:
        void addSceneObject(const SceneObject& object);
        void drawObject(const char* object_name);
};

#endif