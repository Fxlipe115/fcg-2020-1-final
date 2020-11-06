#ifndef _CALLBACKS_H
#define _CALLBACKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);

void errorCallback(int error, const char* description);

#endif