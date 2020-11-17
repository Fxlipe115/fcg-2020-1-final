#include "beziercurve.h"
#include <glm/vec3.hpp>
#include <cmath>



BezierCurve::BezierCurve(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d)
: a(a), b(b), c(c), d(d)
{
}

glm::vec3 BezierCurve::getPointAt(float deltaT) {
    //c(t) = (1-t)^3 * p1 + 3t(1-t)^2 * p2 + 3t^2(1-t) * p3 + t^3 * p4
    float pointX = (pow((1-deltaT),3) * a.x) + (3*deltaT*pow((1-deltaT),2) * b.x) + (3*pow(deltaT,2)*(1-deltaT) * c.x) + (pow(deltaT,3) * d.x);
    float pointY = (pow((1-deltaT),3) * a.y) + (3*deltaT*pow((1-deltaT),2) * b.y) + (3*pow(deltaT,2)*(1-deltaT) * c.y) + (pow(deltaT,3) * d.y);
    float pointZ = (pow((1-deltaT),3) * a.z) + (3*deltaT*pow((1-deltaT),2) * b.z) + (3*pow(deltaT,2)*(1-deltaT) * c.z) + (pow(deltaT,3) * d.z);
  
    return glm::vec3(pointX, pointY, pointZ);
}