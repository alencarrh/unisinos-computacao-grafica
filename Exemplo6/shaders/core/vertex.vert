#version 460 core
layout (location = 0) in vec3 vertex;

out vec3 color;

void main() {
    gl_Position = vec4(vertex, 1.0);
    color = vec3(0.0, 0.0, 0.0);
}    