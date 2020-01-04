#version 330 core

in vec3 gPos;
in vec3 gNormal;
out vec4 fragColor;

uniform mat3 normalMatrix;
uniform sampler2D grass_top0, grass_side1;
uniform float d = 0.1;

const vec4 light_grey = vec4(vec3(0.8), 1);

void main()
{
    vec4 T1 = texture2D(grass_side1, vec2(4*(gPos.x - gPos.y), 1.0 - gPos.z/d));
    vec4 T2 = texture2D(grass_top0, vec2(4*gPos.xy));
    if (gNormal.z == 0) {
        if (T1.a < 0.1) discard;
        else fragColor = T1;
    }
    else fragColor = T2;
}
