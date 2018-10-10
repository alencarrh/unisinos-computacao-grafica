#version 460 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 texture_mapping;

out vec3 color;
out vec2 texture_coordinates;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    color = vec3(1.0f, 1.0f, 1.0f);
	texture_coordinates = vec2(texture_mapping.x, 1.0f - texture_mapping.y);

    gl_Position = projection * view * model * vec4(vertex, 1.0);
}    