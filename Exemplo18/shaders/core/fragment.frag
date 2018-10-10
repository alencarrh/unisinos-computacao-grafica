#version 460 core
out vec4 FragColor;  
 
in vec3 fragmentPos;
in vec3 normal;
in vec2 texture_coordinates;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

// texture samplers
uniform sampler2D texture1;

void main() {
	vec4 texture_color = texture(texture1, texture_coordinates);

	// ambient
	float ambientStrength = 0.1; //TODO remover daqui e passar como uniform
	vec3 ambient = ambientStrength * lightColor;


	// diffuse
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;


	// specular
	float specularStrength = 0.5; //TODO remover daqui e passar como uniform
	vec3 viewDir = normalize(viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256); //TODO '256' remover daqui e passar como uniform
	vec3 specular = specularStrength * spec * lightColor;  

	FragColor = vec4((ambient+diffuse+specular), 1.0) * texture_color;

}
