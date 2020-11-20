#include "axisalignedboundingbox.h"

#include <glm/vec4.hpp>
#include <algorithm>
#include "matrices.h"

AxisAlignedBoundingBox::AxisAlignedBoundingBox(glm::vec3 origin, glm::vec3 size)
 : origin(origin), size(size)
{
}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(ObjectInstance* objectInstance) {
    glm::vec4 objectBoundingBoxMin = glm::vec4(objectInstance->getBoundingBoxMin(), 1.0);
    glm::vec4 objectBoundingBoxMax = glm::vec4(objectInstance->getBoundingBoxMax(), 1.0);
    origin = (objectBoundingBoxMin + objectBoundingBoxMax) * 0.5f;
    size = abs(objectBoundingBoxMax - objectBoundingBoxMin) * 0.5f;
}

glm::vec3 AxisAlignedBoundingBox::getMin() {
    glm::vec3 p1 = origin + size;
    glm::vec3 p2 = origin - size;
    return glm::vec3(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
}

glm::vec3 AxisAlignedBoundingBox::getMax() {
    glm::vec3 p1 = origin + size;
    glm::vec3 p2 = origin - size;
    return glm::vec3(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
}

bool AxisAlignedBoundingBox::isPointInsideBox(glm::vec3 point) {
    glm::vec3 min = getMin();
    glm::vec3 max = getMax();
    if(point.x < min.x || point.y < min.y || point.z < min.z) {
        return false;
    }
    if(point.x > max.x || point.y > max.y || point.z > max.z) { 
        return false;
    }
    return true;
}

glm::vec3 AxisAlignedBoundingBox::closestPointOnSphere(glm::vec3 point) {
    glm::vec3 result = point;
    glm::vec3 min = getMin();
    glm::vec3 max = getMax();

    result.x = (result.x<min.x) ? min.x : result.x;
    result.y = (result.y<min.x) ? min.y : result.y;
    result.z = (result.z<min.x) ? min.z : result.z;

    result.x = (result.x>max.x) ? max.x : result.x;
    result.y = (result.y>max.x) ? max.y : result.y;
    result.z = (result.z>max.x) ? max.z : result.z;
    
    return result;
}
