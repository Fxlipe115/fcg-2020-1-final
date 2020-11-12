#include "objectinstance.h"

#include "matrices.h"

ObjectInstance::ObjectInstance(ObjectModel* model)
 : model(model)
{
    scale = { 1.0f, 1.0f, 1.0f };
    translation = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
}


void ObjectInstance::setScale(Coordinates scale) {
    this->scale = scale;
}


Coordinates ObjectInstance::getScale() {
    return scale;
}

void ObjectInstance::setTranslation(Coordinates translation) {
    this->translation = translation;
}


Coordinates ObjectInstance::getTranslation() {
    return translation;
}


void ObjectInstance::setRotation(Coordinates rotation) {
    this->rotation = rotation;
}


Coordinates ObjectInstance::getRotation() {
    return rotation;
}

void ObjectInstance::draw(GpuProgram* gpuProgram, int shaderFlags) {
    glm::mat4 transformationMatrix = this->transformationMatrix();
        
    gpuProgram->specifyModelMatrix(transformationMatrix);
    gpuProgram->specifyShaderFlags(shaderFlags);
    model->draw();
}

glm::mat4 ObjectInstance::transformationMatrix() {
    return Matrix_Translate(translation.x, translation.y, translation.z)
         * Matrix_Scale(scale.x, scale.y, scale.z)
         * Matrix_Rotate_Z(rotation.z)
         * Matrix_Rotate_Y(rotation.y)
         * Matrix_Rotate_X(rotation.x);
}