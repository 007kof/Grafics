#version 330 core

in vec4 gfrontColor;
in vec3 gNormal;
in vec2 gtexCoord;
in float gtop;
out vec4 fragColor;

uniform sampler2D colorMap;

const vec4 red = vec4(1, 0, 0, 1);
const vec4 green = vec4(0, 1, 0, 1);
const vec4 blue = vec4(0, 0, 1, 1);
const vec4 cyan = vec4(0, 1, 1, 1);
const vec4 yellow = vec4(1, 1, 0, 1);

void main()
{
    float r = distance(gfrontColor, red);
    float g = distance(gfrontColor, green);
    float b = distance(gfrontColor, blue);
    float c = distance(gfrontColor, cyan);
    float y = distance(gfrontColor, yellow);
    float color = min(min(min(min(r, g), b), c), y);
    vec4 C = vec4(0);
    if (color == r) C = red;
    else if (color == g) C = green;
    else if (color == b) C = blue;
    else if (color == c) C = cyan;
    else C = yellow;
    vec4 T = texture2D(colorMap, gtexCoord);
    if (gtop > 0) fragColor = C * gNormal.z * texture2D(colorMap, gtexCoord);
    else fragColor = C * gNormal.z;
}
