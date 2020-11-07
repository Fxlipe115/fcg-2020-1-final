#ifndef _GPUPROGRAM_H
#define _GPUPROGRAM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaders.h"

class GpuProgram {
    private:
        Shaders* shaders;
        GLuint program_id = 0;
        GLint model_uniform;
        GLint view_uniform;
        GLint projection_uniform;
        GLint object_id_uniform;
    public:
        GpuProgram(Shaders* shaders);
        static GLuint createGpuProgram(GLuint vertex_shader_id, GLuint fragment_shader_id);
        GLuint getProgramId();
        GLuint getModelUniform();
        GLuint getViewUniform();
        GLuint getProjectionUniform();
        GLuint getObjectIdUniform();
};

#endif