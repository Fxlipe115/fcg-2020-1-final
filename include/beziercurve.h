#ifndef _BEZIERCURVE_H
#define _BEZIERCURVE_H

#include <glm/vec3.hpp>


class BezierCurve {
    private:
        glm::vec3 a;
        glm::vec3 b;
        glm::vec3 c;
        glm::vec3 d;
    public:
        glm::vec3 getPointAt(float deltaT);
        BezierCurve(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
};

#endif