#ifndef _SHADERS_H
#define _SHADERS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shaders {
    private:

    public:
        GLuint vertex_shader_id;
        GLuint fragment_shader_id;
        GLuint program_id = 0;
        GLint model_uniform;
        GLint view_uniform;
        GLint projection_uniform;
        GLint object_id_uniform;
        Shaders(const char* fragment_shader_path, const char* vertex_shader_path);
        void loadShadersFromFiles(const char* fragment_shader_path, const char* vertex_shader_path);
        GLuint loadShader_Vertex(const char* filename);
        GLuint loadShader_Fragment(const char* filename);
        void loadShader(const char* filename, GLuint shader_id);
};

#endif
