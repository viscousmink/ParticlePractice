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
    Texture texture1("../textures/container.jpg");
    Texture texture2("../textures/awesomeface.png");

    shader.use();
    shader.setInt("texture1", 0);
    shader.setInt("texture2", 1);

    while (!window.shouldClose()) {
        window.processInput();
        window.clear();
        shader.use();
        texture1.bind(0);
        texture2.bind(1);
        mesh.draw();
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}