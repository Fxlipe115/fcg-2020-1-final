#ifndef TEXTRENDERING_H
#define TEXTRENDERING_H

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

GLuint CreateGpuProgram(GLuint vertex_shader_id, GLuint fragment_shader_id); // Função definida em main.cpp

void TextRendering_LoadShader(const GLchar* const shader_string, GLuint shader_id);

void TextRendering_Init();

void TextRendering_PrintString(GLFWwindow* window, const std::string &str, float x, float y, float scale = 1.0f);

float TextRendering_LineHeight(GLFWwindow* window);

float TextRendering_CharWidth(GLFWwindow* window);

void TextRendering_PrintMatrix(GLFWwindow* window, glm::mat4 M, float x, float y, float scale = 1.0f);

void TextRendering_PrintVector(GLFWwindow* window, glm::vec4 v, float x, float y, float scale = 1.0f);

void TextRendering_PrintMatrixVectorProduct(GLFWwindow* window, glm::mat4 M, glm::vec4 v, float x, float y, float scale = 1.0f);

void TextRendering_PrintMatrixVectorProductMoreDigits(GLFWwindow* window, glm::mat4 M, glm::vec4 v, float x, float y, float scale = 1.0f);

void TextRendering_PrintMatrixVectorProductDivW(GLFWwindow* window, glm::mat4 M, glm::vec4 v, float x, float y, float scale = 1.0f);

void TextRendering_ShowModelViewProjection(GLFWwindow* window, glm::mat4 projection, glm::mat4 view, glm::mat4 model, glm::vec4 p_model, bool showInfoText);

void TextRendering_ShowEulerAngles(GLFWwindow* window, float angleX, float angleY, float angleZ, bool showInfoText);

void TextRendering_ShowProjection(GLFWwindow* window, bool showInfoText, bool usePerspectiveProjection);

void TextRendering_ShowFramesPerSecond(GLFWwindow* window, bool showInfoText);


#endif