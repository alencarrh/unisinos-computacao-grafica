#version 330 core
out vec4 FragColor;  
//in vec3 ourColor;
  
uniform vec3 control_points_color;

void main() {
    FragColor = vec4(control_points_color, 1.0);
}
