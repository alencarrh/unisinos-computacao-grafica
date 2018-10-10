#version 460 core
out vec4 FragColor;  
 
in vec3 color;
in vec2 texture_coordinates;

// texture samplers
uniform sampler2D texture1;

void main() {
    FragColor = texture(texture1, texture_coordinates) * vec4(color, 1.0);
}
