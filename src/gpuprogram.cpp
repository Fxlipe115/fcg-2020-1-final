#include "gpuprogram.h"

#include <cstdio>
#include <string>

#include <glm/gtc/type_ptr.hpp>

#include "utils.h"

GpuProgram::GpuProgram(Shaders* shaders) {
    // Deletamos o programa de GPU anterior, caso ele exista.
    if ( program_id != 0 )
        glDeleteProgram(program_id);

    // Criamos um programa de GPU utilizando os shaders carregados acima.
    program_id = createGpuProgram(shaders->vertex_shader_id, shaders->fragment_shader_id);

    // Buscamos o endereço das variáveis definidas dentro do Vertex Shader.
    // Utilizaremos estas variáveis para enviar dados para a placa de vídeo
    // (GPU)! Veja arquivo "shader_vertex.glsl" e "shader_fragment.glsl".
    model_uniform           = glGetUniformLocation(program_id, "model"); // Variável da matriz "model"
    view_uniform            = glGetUniformLocation(program_id, "view"); // Variável da matriz "view" em shader_vertex.glsl
    projection_uniform      = glGetUniformLocation(program_id, "projection"); // Variável da matriz "projection" em shader_vertex.glsl
    shader_flags_uniform    = glGetUniformLocation(program_id, "shader_flags"); // Variável "object_id" em shader_fragment.glsl
}

// Esta função cria um programa de GPU, o qual contém obrigatoriamente um
// Vertex Shader e um Fragment Shader.
GLuint GpuProgram::createGpuProgram(GLuint vertex_shader_id, GLuint fragment_shader_id) {
    // Criamos um identificador (ID) para este programa de GPU
    GLuint program_id = glCreateProgram();

    // Definição dos dois shaders GLSL que devem ser executados pelo programa
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);

    // Linkagem dos shaders acima ao programa
    glLinkProgram(program_id);

    // Verificamos se ocorreu algum erro durante a linkagem
    GLint linked_ok = GL_FALSE;
    glGetProgramiv(program_id, GL_LINK_STATUS, &linked_ok);

    // Imprime no terminal qualquer erro de linkagem
    if ( linked_ok == GL_FALSE )
    {
        GLint log_length = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &log_length);

        // Alocamos memória para guardar o log de compilação.
        // A chamada "new" em C++ é equivalente ao "malloc()" do C.
        GLchar* log = new GLchar[log_length];

        glGetProgramInfoLog(program_id, log_length, &log_length, log);

        std::string output;

        output += "ERROR: OpenGL linking of program failed.\n";
        output += "== Start of link log\n";
        output += log;
        output += "\n== End of link log\n";

        // A chamada "delete" em C++ é equivalente ao "free()" do C
        delete [] log;

        fprintf(stderr, "%s", output.c_str());
    }

    // Os "Shader Objects" podem ser marcados para deleção após serem linkados 
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    // Retornamos o ID gerado acima
    return program_id;
}


void GpuProgram::use() {
    glUseProgram(program_id);
}


void GpuProgram::specifyModelMatrix(glm::mat4 modelMatrix) {
    glUniformMatrix4fv(model_uniform, 1 , GL_FALSE , glm::value_ptr(modelMatrix));
}


void GpuProgram::specifyViewMatrix(glm::mat4 viewMatrix) {
    glUniformMatrix4fv(view_uniform , 1 , GL_FALSE , glm::value_ptr(viewMatrix));
        
}


void GpuProgram::specifyProjectionMatrix(glm::mat4 projectionMatrix) {
    glUniformMatrix4fv(projection_uniform , 1 , GL_FALSE , glm::value_ptr(projectionMatrix));
}


void GpuProgram::specifyShaderFlags(int shaderFlags) {
    glUniform1i(shader_flags_uniform, shaderFlags);
}
