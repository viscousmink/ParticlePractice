#define GLFW_INCLUDE_NONE
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"

int main() {
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    Window window(800, 600, "ParticlePractice");
    Shader shader("../shaders/triangle_vertex.glsl", "../shaders/triangle_fragment.glsl");
    Mesh mesh(vertices, sizeof(vertices), indices, sizeof(indices));

    while (!window.shouldClose()) {
        window.processInput();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        mesh.draw();
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}