#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

class Camera {
public:
    Camera(const glm::vec3& position, const glm::vec3& up, float yaw, float pitch);

    glm::mat4 getViewMatrix() const;
    void processKeyboard(float deltaTime, GLFWwindow* window);
    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    glm::vec3 getPosition() const;
    void setPosition(const glm::vec3& position);
    glm::vec3 getFront() const;

    const float cameraSpeed = 0.05f; // adjust accordingly

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    float yaw;
    float pitch;

    float movementSpeed;
    float mouseSensitivity;

    void updateCameraVectors();
};

#endif