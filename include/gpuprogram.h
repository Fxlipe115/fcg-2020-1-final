#ifndef _GPUPROGRAM_H
#define _GPUPROGRAM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLuint createGpuProgram(GLuint vertex_shader_id, GLuint fragment_shader_id);

#endif