#include "Model.h"

Model::Model(Shader* shader, Mesh* mesh, Texture* texture1, Texture* texture2)
    : shader(shader), mesh(mesh), texture1(texture1), texture2(texture2), position(0.0f), scale(1.0f), rotationAngle(0.0f), rotationAxis(0.0f, 1.0f, 0.0f), modelMatrix(1.0f) {
}

Model::~Model() {
    // Note: Deletion of shader, mesh, or texture should be handled outside if they are shared
}

void Model::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
    updateModelMatrix();
}

void Model::setRotation(float angle, const glm::vec3& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
    updateModelMatrix();
}

void Model::setScale(const glm::vec3& newScale) {
    scale = newScale;
    updateModelMatrix();
}

glm::vec3 Model::getPosition() const {
    return position;
}

void Model::updateModelMatrix() {
    modelMatrix = glm::mat4(1.0f); // Reset to identity matrix
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, rotationAngle, rotationAxis);
    modelMatrix = glm::scale(modelMatrix, scale);
}

void Model::draw(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
    shader->use();
    // need some kind of for loop for the textures... maybe an array of textures?
    texture1->bind(0);
    texture2->bind(1);
    shader->setMat4("model", modelMatrix);
    shader->setMat4("view", viewMatrix);
    shader->setMat4("projection", projectionMatrix);
    mesh->draw();
    texture1->unbind();
    texture2->unbind();
}
