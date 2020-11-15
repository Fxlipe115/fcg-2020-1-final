#ifndef _OBJECTINSTANCE_H
#define _OBJECTINSTANCE_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "gpuprogram.h"
#include "objectmodel.h"
#include "shaderflags.h"

class ObjectInstance {
    private:
        ObjectModel* model;
        glm::vec3 scale;
        glm::vec3 translation;
        glm::vec3 rotation;
        glm::mat4 transformationMatrix();
    public:
        ObjectInstance(ObjectModel* model);
        void setScale(glm::vec3 scale);
        glm::vec3 getScale();
        void setTranslation(glm::vec3 translation);
        glm::vec3 getTranslation();
        void setRotation(glm::vec3 rotation);
        glm::vec3 getRotation();
        glm::vec4 getFrontVector();
        void draw(GpuProgram* gpuProgram, int shaderFlags);
};

#endif