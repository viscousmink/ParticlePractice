#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

#include "Camera.h"

extern Camera* camera;

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    inline static const glm::mat4 getViewMatrix() { return camera->getViewMatrix(); };
    bool shouldClose() const;
    void processInput(float deltaTime);
    void swapBuffers();
    void clear();
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
    bool firstMouse = false;
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
