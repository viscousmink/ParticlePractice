#include "Model.h"

Model::Model(Shader* shader, Mesh* mesh, Texture* textures)
    : shader(shader), mesh(mesh), textures(textures), position(0.0f), scale(1.0f), rotationAngle(0.0f), rotationAxis(0.0f, 1.0f, 0.0f), modelMatrix(1.0f) {
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
    for(int i = 0; i < sizeof(textures) / sizeof(Texture); i++)
    {
        textures[i].bind(i);
    }
    shader->setMat4("model", modelMatrix);
    shader->setMat4("view", viewMatrix);
    shader->setMat4("projection", projectionMatrix);
    // Adding in lighting stuff, will need to move elsewhere when it makes more sense...
    shader->setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    shader->setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));
    mesh->draw();
    for(int i = 0; i < sizeof(textures) / sizeof(Texture); i++)
    {
        textures[i].unbind();
    }
}
