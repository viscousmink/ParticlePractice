#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"


int main() {
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    Window window(800, 600, "ParticlePractice");
    Shader shader("../shaders/triangle_vertex.glsl", "../shaders/triangle_fragment.glsl");
    Mesh mesh(vertices, sizeof(vertices), indices, sizeof(indices));
    Texture myTexture("../textures/wall.jpg");

    while (!window.shouldClose()) {
        window.processInput();
        window.clear();
        shader.use();
        myTexture.bind();
        mesh.draw();
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}