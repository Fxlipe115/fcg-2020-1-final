#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

#include <stack>

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

class MatrixStack {
    private:
        std::stack<glm::mat4>  matrixStack;

    public:
        void pushMatrix(glm::mat4 M);
        void popMatrix(glm::mat4& M);
};

#endif