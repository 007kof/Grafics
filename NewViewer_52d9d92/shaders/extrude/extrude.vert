#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 3) in vec2 texCoord;

out vec4 vfrontColor;
out vec3 vNormal;

uniform mat3 normalMatrix;

void main()
{
    vec3 N = normalize(normalMatrix * normal);
    vfrontColor = N.z;
    vNormal = normal;
    gl_Position = vec4(vertex, 1.0);
}
