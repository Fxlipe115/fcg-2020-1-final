#ifndef _CALLBACKS_H
#define _CALLBACKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "keyboardparameters.h"
#include "mouseparameters.h"
#include "windowparameters.h"

class Callbacks {
private:
    Callbacks();
    static Callbacks* instance;
    WindowParameters* windowParameters;
    MouseParameters* mouseParameters;
    KeyboardParameters* keyboardParameters;

public:
    static Callbacks* getInstance();
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);
    static void errorCallback(int error, const char* description);
    void setWindowParameters(WindowParameters* windowParameters);
    void setMouseParameters(MouseParameters* mouseParameters);
    void setKeyboardParameters(KeyboardParameters* keyboardParameters);
};

#endif