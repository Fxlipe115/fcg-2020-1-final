#include "objectinstance.h"

#include <glm/vec4.hpp>

#include "matrices.h"

ObjectInstance::ObjectInstance(ObjectModel* model)
 : model(model)
{
    scale = { 1.0f, 1.0f, 1.0f };
    translation = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
}

ObjectModel* ObjectInstance::getModel() {
    return model;
}


void ObjectInstance::setScale(glm::vec3 scale) {
    this->scale = scale;
}


glm::vec3 ObjectInstance::getScale() {
    return scale;
}

void ObjectInstance::setTranslation(glm::vec3 translation) {
    this->translation = translation;
}


glm::vec3 ObjectInstance::getTranslation() {
    return translation;
}


void ObjectInstance::setRotation(glm::vec3 rotation) {
    this->rotation = rotation;
}


glm::vec3 ObjectInstance::getRotation() {
    return rotation;
}

glm::vec4 ObjectInstance::getFrontVector() {
    glm::vec4 front = glm::vec4(0.0, 0.0, 1.0, 0.0)
                    * Matrix_Rotate_Y(-rotation.y);

    return front/norm(front);
}

void ObjectInstance::draw(GpuProgram* gpuProgram, int shaderFlags) {
    glm::mat4 transformationMatrix = this->transformationMatrix();
        
    gpuProgram->sendModelMatrixToGPU(transformationMatrix);
    gpuProgram->sendShaderFlagsToGPU(shaderFlags);
    model->draw(gpuProgram);
}

glm::mat4 ObjectInstance::transformationMatrix() {
    return Matrix_Translate(translation.x, translation.y, translation.z)
         * Matrix_Scale(scale.x, scale.y, scale.z)
         * Matrix_Rotate_Z(rotation.z)
         * Matrix_Rotate_Y(rotation.y)
         * Matrix_Rotate_X(rotation.x);
}

glm::vec3 ObjectInstance::getBoundingBoxMin() {
    glm::vec4 rotatedBoundingBoxMin = glm::vec4(model->getBoundingBoxMin(), 0.0);
    rotatedBoundingBoxMin = transformationMatrix() * rotatedBoundingBoxMin;
    return glm::vec3(rotatedBoundingBoxMin);
}

glm::vec3 ObjectInstance::getBoundingBoxMax() {
    glm::vec4 rotatedBoundingBoxMax = glm::vec4(model->getBoundingBoxMax(), 0.0);
    rotatedBoundingBoxMax = transformationMatrix() * rotatedBoundingBoxMax;
    return glm::vec3(rotatedBoundingBoxMax);
}