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
        BezierCurve(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
        glm::vec3 getPointAt(float deltaT);
        glm::vec3 getA();
        glm::vec3 getB();
        glm::vec3 getC();
        glm::vec3 getD();
};

#endif