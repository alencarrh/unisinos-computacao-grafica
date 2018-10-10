#version 460 core
out vec4 FragColor;  
 
uniform vec3 lightColor;
in vec2 texture_coordinates;

// texture samplers
uniform sampler2D texture1;

void main() {
	vec4 texture_color = texture(texture1, texture_coordinates);
	
	float ambientStrength = 0.1;
	
	vec3 ambient = ambientStrength * lightColor;
	//vec4 object_color = vec4(lightColor, 1.0);


	FragColor = vec4(ambient, 1.0) * texture_color;

}
