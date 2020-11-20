#ifndef _AXISALIGNEDBOUNDINGBOX_H
#define _AXISALIGNEDBOUNDINGBOX_H

#include <glm/vec3.hpp>

#include "objectinstance.h"


class AxisAlignedBoundingBox {
    private:
        glm::vec3 origin;
        glm::vec3 size;
    public:
        AxisAlignedBoundingBox(glm::vec3 origin, glm::vec3 size);
        AxisAlignedBoundingBox(ObjectInstance* objectInstance);
        glm::vec3 getMin();
        glm::vec3 getMax();
        bool isPointInsideBox(glm::vec3 point);
        glm::vec3 closestPointOnSphere(glm::vec3 point);
};

#endif