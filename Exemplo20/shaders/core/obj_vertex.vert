#version 330 core
layout (location = 0) in vec3 inVertex;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexture_mapping;

out vec2 texture_coordinates;
out vec3 normal;
out vec3 fragmentPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	vec4 model_times_vertex = model * vec4(inVertex, 1.0);
	
	gl_Position = projection * view * model_times_vertex;

	//valores a serem passados ao fragmentShader
	texture_coordinates = vec2(inTexture_mapping.x, 1.0f - inTexture_mapping.y);
	normal = mat3(transpose(inverse(model))) * inNormal;  
	fragmentPos = vec3(model_times_vertex);
}    