#ifndef _OBJECTINSTANCE_H
#define _OBJECTINSTANCE_H

#include "glm/mat4x4.hpp"

#include "coordinates.h"
#include "gpuprogram.h"
#include "objectmodel.h"
#include "shaderflags.h"

class ObjectInstance {
    private:
        ObjectModel* model;
        Coordinates scale;
        Coordinates translation;
        Coordinates rotation;
        glm::mat4 transformationMatrix();
    public:
        ObjectInstance(ObjectModel* model);
        void setScale(Coordinates scale);
        Coordinates getScale();
        void setTranslation(Coordinates translation);
        Coordinates getTranslation();
        void setRotation(Coordinates rotation);
        Coordinates getRotation();
        void draw(GpuProgram* gpuProgram, ShaderFlags shaderFlags);
};

#endif