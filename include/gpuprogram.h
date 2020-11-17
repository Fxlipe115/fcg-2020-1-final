#ifndef _GPUPROGRAM_H
#define _GPUPROGRAM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glm/mat4x4.hpp"
#include "shaders.h"

class GpuProgram {
    private:
        Shaders* shaders;
        GLuint program_id = 0;
        GLint model_uniform;
        GLint view_uniform;
        GLint projection_uniform;
        GLint shader_flags_uniform;
    public:
        GpuProgram(Shaders* shaders);
        static GLuint createGpuProgram(GLuint vertex_shader_id, GLuint fragment_shader_id);
        void use();
        void sendModelMatrixToGPU(glm::mat4 modelMatrix);
        void sendViewMatrixToGPU(glm::mat4 viewMatrix);
        void sendProjectionMatrixToGPU(glm::mat4 projectionMatrix);
        void sendShaderFlagsToGPU(int shaderFlags);
};

#endif