#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

#include "Camera.h"

class Window {
public:
    Window(int width, int height, const char* title, Camera& camera);
    ~Window();
    bool shouldClose() const;
    void processInput(float deltaTime);
    void swapBuffers();
    void clear();
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
    Camera& camera;
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
