#version 330 core
out vec4 FragColor;  
 
in vec3 fragmentPos;
in vec3 normal;
in vec2 texture_coordinates;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

// texture samplers
uniform sampler2D texture1;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 
uniform Material material;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Light light;  

void main() {
	vec4 texture_color = texture(texture1, texture_coordinates);

	//ambient
	vec3 ambient = material.ambient * light.ambient;

	// diffuse
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = lightColor * (diff * material.diffuse) * light.diffuse;

	// specular
	vec3 viewDir = normalize(viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = lightColor * (spec * material.specular) * light.specular;
		
	vec3 final_light = ambient + diffuse + specular;

	FragColor = vec4(final_light, 1.0) * texture_color;

}
