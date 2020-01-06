#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 2) in vec3 color;

out vec4 frontColor;

uniform vec3 boundingBoxMax, boundingBoxMin;
uniform mat4 modelViewProjectionMatrix;

void main()
{
    vec3 scale = boundingBoxMax - boundingBoxMin;
    mat4 S = mat4(vec4(scale.x, 0, 0, 0), vec4(0, scale.y, 0, 0), vec4(0, 0, scale.z, 0), vec4(vec3(0), 1));
    frontColor = vec4(color, 1);
    vec4 C = vec4((boundingBoxMin + boundingBoxMax) / 2, 0);
    vec4 V = S * (vec4(vertex-vec3(0.5), 1) + C);
    gl_Position = modelViewProjectionMatrix * V;
}
