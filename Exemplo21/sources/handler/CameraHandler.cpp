#include "../../headers/handler/CameraHandler.h"

glm::mat4 CameraHandler::getViewMatrix() {
    return lookAt(position, position + front, up);
}

void CameraHandler::processKeyboard(Camera_Movement direction, float deltaTime) {
    float velocity = movementSpeed * deltaTime;
    if (direction == FORWARD) position += front * velocity;
    if (direction == BACKWARD) position -= front * velocity;
    if (direction == LEFT) position -= right * velocity;
    if (direction == RIGHT) position += right * velocity;
    if (direction == UP) position += up * velocity;
    if (direction == DOWN) position -= up * velocity;


}

void CameraHandler::processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch) {
        if (pitch > MAX_PITCH) {
            pitch = MAX_PITCH;
        }
        if (pitch < MIN_PITCH) {
            pitch = MIN_PITCH;
        }
    }

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();

}

void CameraHandler::processMouseScroll(float yoffset) {
    if (zoom >= MIN_ZOOM && zoom <= MAX_ZOOM) {
        zoom -= yoffset;
    }
    if (zoom <= MIN_ZOOM) {
        zoom = MIN_ZOOM;
    }
    if (zoom >= MAX_ZOOM) {
        zoom = MAX_ZOOM;
    }
}

void CameraHandler::updateCameraVectors() {
    // Calculate the new Front vector
    glm::vec3 _front;
    _front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    _front.y = sin(glm::radians(pitch));
    _front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    this->front = normalize(_front);

    // Also re-calculate the Right and Up vector
    right = normalize(cross(front, worldUp)); //Normalize the vectors, because their length gets closer to 0 
    up = normalize(cross(right, front)); //     the more you look up or down which results in slower movement.
}
