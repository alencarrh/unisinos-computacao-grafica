#version 460 core
layout (location = 0) in vec3 vertex;

out vec3 color;

uniform mat4 view;

void main() {
    gl_Position = view * vec4(vertex, 1.0);
    color = vec3(0.0, 0.0, 0.0);
}    