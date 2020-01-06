#version 330 core

in vec3 NormalFS;
in vec3 VertexFS;
out vec4 fragColor;

uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec4 matAmbient, matDiffuse, matSpecular;
uniform float matShininess;
uniform vec4 lightAmbient, lightDiffuse, lightSpecular, lightPosition;

vec4 phong(vec3 N, vec3 L, vec3 V) {
	vec3 R = normalize(2 * dot(N, L) * N - L);
	vec4 ambient = lightAmbient * matAmbient;
	vec4 difusa = lightDiffuse * matDiffuse * max(0.0, dot(N, L));
	vec4 especular = lightSpecular * matSpecular * pow(max(0.0, dot(R, V)), matShininess);
	if (dot(N, L) < 0) especular = vec4(0.0, 0.0, 0.0, 0.0);
	return ambient + difusa + especular;
}

void main()
{
	vec3 N = normalize(normalMatrix * NormalFS);
	vec3 L = normalize((lightPosition - modelViewMatrix * vec4(VertexFS, 1.0)).xyz);
	vec3 V = normalize(-(modelViewMatrix * vec4(VertexFS, 1.0)).xyz);
    fragColor = phong(N, L, V);
}
