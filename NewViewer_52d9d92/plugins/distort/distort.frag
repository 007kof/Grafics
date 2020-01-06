#version 330 core

out vec4 fragColor;

uniform sampler2D colorMap;
uniform float SIZE, time;

const int W = 4;

void main() {
    vec2 st = (gl_FragCoord.xy - vec2(0.5)) / SIZE;
    fragColor = texture(colorMap, st + 0.01 * sin(10.0 * time + 30 * st.x));
}
