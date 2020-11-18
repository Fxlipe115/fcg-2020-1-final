#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

class Camera {
    protected:
        glm::vec3 position;
        float theta;
        float phi;
        float distance;
        float nearPlane;
        float farPlane;
        virtual glm::vec4 getViewVector() = 0;
        glm::vec4 getPosition();
        glm::vec4 getUpVector();
    public:
        Camera();
        virtual ~Camera();
        virtual void setPosition(glm::vec3 position);
        float getTheta();
        void setTheta(float theta);
        float getPhi();
        void setPhi(float phi);
        float getDistance();
        void setDistance(float distance);
        float getNearPlane();
        void setNearPlane(float nearPlane);
        float getFarPlane();
        void setFarPlane(float farPlane);
        virtual bool isFreeCamera() = 0;
        glm::mat4 getViewMatrix();
};

#endif