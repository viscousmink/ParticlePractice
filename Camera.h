#ifndef CAMERA_H
#define CAMERA_H

#define GLFW_INCLUDE_NONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtx/string_cast.hpp>
#include <glad/glad.h>

#include <iostream>

class Camera {
public:
    Camera(const glm::vec3& position, const glm::vec3& up, float yaw, float pitch, float fov);
    
    void processKeyboard(float deltaTime, GLFWwindow* window);

    void processMouse(float xposIn, float yposIn, GLboolean constrainPitch = true);
    void processScroll(double xoffset, double yoffset);

    glm::vec3 getFront() const;
    glm::vec3 getPosition() const;
    glm::mat4 getViewMatrix() const;
    void setPosition(const glm::vec3& position);

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

    bool firstMouse = true;
    float lastX;
    float lastY;
    float fov;

    void updateCameraVectors();
};

#endif