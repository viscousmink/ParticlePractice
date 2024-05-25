#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();
    bool shouldClose() const;
    void processInput();
    void swapBuffers();
    void clear();
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
