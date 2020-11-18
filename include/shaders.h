#ifndef _SHADERS_H
#define _SHADERS_H

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shaders {
    private:
        void loadShadersFromFiles(const char* fragment_shader_path, const char* vertex_shader_path);
        GLuint loadShader_Vertex(const char* filename);
        GLuint loadShader_Fragment(const char* filename);
        void loadShader(const char* filename, GLuint shader_id);
        std::string fragmentShaderPath;
        std::string vertexShaderPath;
    public:
        GLuint vertex_shader_id;
        GLuint fragment_shader_id;
        Shaders(const char* fragment_shader_path, const char* vertex_shader_path);
        void reload();
};

#endif
