#version 460 core
out vec4 FragColor;  
 
in vec3 fragmentPos;
in vec3 normal;
in vec2 texture_coordinates;

uniform vec3 lightColor;
uniform vec3 lightPos;

// texture samplers
uniform sampler2D texture1;

void main() {
	vec4 texture_color = texture(texture1, texture_coordinates);

	// ambient
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;


	// diffuse
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	FragColor = vec4((ambient+diffuse), 1.0) * texture_color;

}
