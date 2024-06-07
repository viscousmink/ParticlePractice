#ifndef MODEL_H
#define MODEL_H

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

class Model {
public:
    Model(Shader* shader, Mesh* mesh, Texture* textures);
    ~Model();

    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    glm::vec3 getPosition() const;

    void draw(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
    void resetModelMatrix();
    void updateModelMatrix();

    void printModelMatrix() {std::cout << glm::to_string(modelMatrix) << std::endl;};

private:
    Shader* shader;
    Mesh* mesh;
    Texture* textures;
    glm::mat4 modelMatrix;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

#endif
