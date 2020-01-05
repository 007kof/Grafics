#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;

out vec4 frontColor;

uniform float time;
uniform float amplitude = 0.1;
uniform float freq = 1;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

const float PI = 3.141592;

void main() {
	float d = amplitude * sin(2 * PI * freq * time);
	vec3 Normal = normalize(normalMatrix * normal);
    vec3 N = normalize(normal);
    frontColor = vec4(Normal.z);
    gl_Position = modelViewProjectionMatrix * vec4(vertex + d * N, 1.0);
}
