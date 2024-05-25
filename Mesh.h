#ifndef MESH_H
#define MESH_H

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <cstddef>

class Mesh {
public:
    Mesh(const float* vertices, size_t verticesSize, const unsigned int* indices, size_t indicesSize);
    ~Mesh();
    void draw();

private:
    unsigned int VBO, VAO, EBO;
    size_t vertexCount, indexCount;
    void setupMesh(const float* vertices, size_t verticesSize, const unsigned int* indices, size_t indicesSize);
};

#endif
