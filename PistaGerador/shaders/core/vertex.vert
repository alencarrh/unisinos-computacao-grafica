#version 330 core
layout (location = 0) in vec3 values;

uniform mat4 projection;

void main() {
    gl_Position = projection * vec4(values.x, values.y, 0.0, 1.0);
}    