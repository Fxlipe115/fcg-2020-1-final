#include "callbacks.h"

#include <cstdio>
#include <limits>


Callbacks* Callbacks::instance = nullptr;

Callbacks* Callbacks::getInstance() {
    if(instance == nullptr) {
        instance = new Callbacks();
    }
    return instance;
}

Callbacks::Callbacks() {
}

void Callbacks::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    Callbacks* callbacks = Callbacks::getInstance();
    WindowParameters* windowParameters = callbacks->windowParameters;

    // Indicamos que queremos renderizar em toda região do framebuffer. A
    // função "glViewport" define o mapeamento das "normalized device
    // coordinates" (NDC) para "pixel coordinates".  Essa é a operação de
    // "Screen Mapping" ou "Viewport Mapping" vista em aula ({+ViewportMapping2+}).
    glViewport(0, 0, width, height);

    // Atualizamos também a razão que define a proporção da janela (largura /
    // altura), a qual será utilizada na definição das matrizes de projeção,
    // tal que não ocorra distorções durante o processo de "Screen Mapping"
    // acima, quando NDC é mapeado para coordenadas de pixels. Veja slides 205-215 do documento Aula_09_Projecoes.pdf.
    //
    // O cast para float é necessário pois números inteiros são arredondados ao
    // serem divididos!
    windowParameters->screenRatio = (float)width / height;
}


void Callbacks::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    Callbacks* callbacks = Callbacks::getInstance();
    MouseParameters* mouseParameters = callbacks->mouseParameters;

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        glfwGetCursorPos(window, &mouseParameters->lastCursorPositionX, &mouseParameters->lastCursorPositionY);
        mouseParameters->leftButtonPressed = true;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        // Quando o usuário soltar o botão esquerdo do mouse, atualizamos a
        // variável abaixo para false.
        mouseParameters->leftButtonPressed = false;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        // Se o usuário pressionou o botão esquerdo do mouse, guardamos a
        // posição atual do cursor nas variáveis g_LastCursorPosX e
        // g_LastCursorPosY.  Também, setamos a variável
        // g_RightMouseButtonPressed como true, para saber que o usuário está
        // com o botão esquerdo pressionado.
        glfwGetCursorPos(window, &mouseParameters->lastCursorPositionX, &mouseParameters->lastCursorPositionY);
        mouseParameters->rightButtonPressed = true;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        // Quando o usuário soltar o botão esquerdo do mouse, atualizamos a
        // variável abaixo para false.
        mouseParameters->rightButtonPressed = false;
    }
    if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
        // Se o usuário pressionou o botão esquerdo do mouse, guardamos a
        // posição atual do cursor nas variáveis g_LastCursorPosX e
        // g_LastCursorPosY.  Também, setamos a variável
        // g_MiddleMouseButtonPressed como true, para saber que o usuário está
        // com o botão esquerdo pressionado.
        glfwGetCursorPos(window, &mouseParameters->lastCursorPositionX, &mouseParameters->lastCursorPositionY);
        mouseParameters->middleButtonPressed = true;
    }
    if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE) {
        // Quando o usuário soltar o botão esquerdo do mouse, atualizamos a
        // variável abaixo para false.
        mouseParameters->middleButtonPressed = false;
    }
}


void Callbacks::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    Callbacks* callbacks = Callbacks::getInstance();
    MouseParameters* mouseParameters = callbacks->mouseParameters;

    float dx = xpos - mouseParameters->lastCursorPositionX;
    float dy = ypos - mouseParameters->lastCursorPositionY;


    if (mouseParameters->leftButtonPressed) {
        // Atualizamos parâmetros da câmera com os deslocamentos
        mouseParameters->rotationAngleTheta -= 0.01f*dx;
        mouseParameters->rotationAnglePhi += 0.01f*dy;
    
        // Em coordenadas esféricas, o ângulo phi deve ficar entre -pi/2 e +pi/2.
        float phimax = 3.141592f/2;
        float phimin = -phimax;
    
        if (mouseParameters->rotationAnglePhi > phimax)
            mouseParameters->rotationAnglePhi = phimax;
    
        if (mouseParameters->rotationAnglePhi < phimin)
            mouseParameters->rotationAnglePhi = phimin;
    }

    if (mouseParameters->rightButtonPressed) {
        // Do something
    }

    if (mouseParameters->middleButtonPressed) {
         // Do something
    }

    mouseParameters->lastCursorPositionX = xpos;
    mouseParameters->lastCursorPositionY = ypos;
}


void Callbacks::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    Callbacks* callbacks = Callbacks::getInstance();
    MouseParameters* mouse = callbacks->mouseParameters;

    // Atualizamos a distância da câmera para a origem utilizando a
    // movimentação da "rodinha", simulando um ZOOM.
    mouse->wheelOffset -= 0.1f*yoffset;

    // Uma câmera look-at nunca pode estar exatamente "em cima" do ponto para
    // onde ela está olhando, pois isto gera problemas de divisão por zero na
    // definição do sistema de coordenadas da câmera. Isto é, a variável abaixo
    // nunca pode ser zero. Versões anteriores deste código possuíam este bug,
    // o qual foi detectado pelo aluno Vinicius Fraga (2017/2).
    const float verysmallnumber = std::numeric_limits<float>::epsilon();
    if (mouse->wheelOffset < verysmallnumber)
        mouse->wheelOffset = verysmallnumber;
}


void Callbacks::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod) {
    Callbacks* callbacks = Callbacks::getInstance();
    KeyboardParameters* keyboardParameters = callbacks->keyboardParameters;

    // Se o usuário pressionar a tecla ESC, fechamos a janela.
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::ESC_SWITCH_KEY);
        glfwSetWindowShouldClose(window, GL_TRUE);
    }


    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::SPACE_SWITCH_KEY);
    }

    // Se o usuário apertar a tecla P, utilizamos projeção perspectiva.
    if (key == GLFW_KEY_P && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::P_SWITCH_KEY);
    }

    // Se o usuário apertar a tecla O, utilizamos projeção ortográfica.
    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::O_SWITCH_KEY);
    }

    // Se o usuário apertar a tecla H, fazemos um "toggle" do texto informativo mostrado na tela.
    if (key == GLFW_KEY_H && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::H_SWITCH_KEY);
    }

    // Se o usuário apertar a tecla R, recarregamos os shaders dos arquivos "shader_fragment.glsl" e "shader_vertex.glsl".
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::R_SWITCH_KEY);
    }

    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        keyboardParameters->pressedSwitches.push_back(SwitchKeys::C_SWITCH_KEY);
    }

    if(key == GLFW_KEY_W) {
        if(action == GLFW_PRESS) {
            keyboardParameters->upKeyPressed = true;
        }
        else if(action == GLFW_RELEASE) {
            keyboardParameters->upKeyPressed =false;
        }
    }

    if(key == GLFW_KEY_S) {
        if(action == GLFW_PRESS) {
            keyboardParameters->downKeyPressed = true;
        }
        else if(action == GLFW_RELEASE) {
            keyboardParameters->downKeyPressed =false;
        }
    }

    if(key == GLFW_KEY_A) {
        if(action == GLFW_PRESS) {
            keyboardParameters->leftKeyPressed = true;
        }
        else if(action == GLFW_RELEASE) {
            keyboardParameters->leftKeyPressed =false;
        }
    }

    if(key == GLFW_KEY_D) {
        if(action == GLFW_PRESS) {
            keyboardParameters->rightKeyPressed = true;
        }
        else if(action == GLFW_RELEASE) {
            keyboardParameters->rightKeyPressed =false;
        }
    }
}



void Callbacks::errorCallback(int error, const char* description) {
    fprintf(stderr, "ERROR: GLFW: %s\n", description);
}


void Callbacks::setWindowParameters(WindowParameters* windowParameters) {
    this->windowParameters = windowParameters;
}

void Callbacks::setMouseParameters(MouseParameters* mouseParameters) {
    this->mouseParameters = mouseParameters;
}

void Callbacks::setKeyboardParameters(KeyboardParameters* keyboardParameters) {
    this->keyboardParameters = keyboardParameters;
}

