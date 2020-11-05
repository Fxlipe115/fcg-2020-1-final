#include "matrixstack.h"
#include "matrices.h"

// Função que pega a matriz M e guarda a mesma no topo da pilha
void MatrixStack::pushMatrix(glm::mat4 M)
{
    this->matrixStack.push(M);
}

// Função que remove a matriz atualmente no topo da pilha e armazena a mesma na variável M
void MatrixStack::popMatrix(glm::mat4& M)
{
    if ( this->matrixStack.empty() )
    {
        M = Matrix_Identity();
    }
    else
    {
        M = this->matrixStack.top();
        this->matrixStack.pop();
    }
}