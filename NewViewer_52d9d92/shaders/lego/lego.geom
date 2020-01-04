#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;
out vec3 gNormal;
out vec2 gtexCoord;
out float gtop;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float step = 0.2;

void draw_face(vec3 N, vec4 C, vec3 V[6], bool top, vec3 B) {
    gtop = top ? 1.0 : 0.0;
    gtexCoord = vec2(V[0].x,V[0].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[0]*step+B, 1.0);
    EmitVertex();
    gtexCoord = vec2(V[1].x,V[1].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[1]*step+B, 1.0);
    EmitVertex();
    gtexCoord = vec2(V[2].x,V[2].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[2]*step+B, 1.0);
    EmitVertex();
    EndPrimitive();
    gtexCoord = vec2(V[3].x,V[3].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[3]*step+B, 1.0);
    EmitVertex();
    gtexCoord = vec2(V[4].x,V[4].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[4]*step+B, 1.0);
    EmitVertex();
    gtexCoord = vec2(V[5].x,V[5].z);
    gNormal = N;
    gfrontColor = C;
    gl_Position = modelViewProjectionMatrix * vec4(V[5]*step+B, 1.0);
    EmitVertex();
    EndPrimitive();
}

void draw_cube(vec3 B, vec4 C) {
    vec3 V1 = vec3(0, 0, 0);
    vec3 V2 = vec3(0, 0, 1);
    vec3 V3 = vec3(0, 1, 0);
    vec3 V4 = vec3(0, 1, 1);
    vec3 V5 = vec3(1, 0, 0);
    vec3 V6 = vec3(1, 0, 1);
    vec3 V7 = vec3(1, 1, 0);
    vec3 V8 = vec3(1, 1, 1);
    
    /*vec3 V1 = vec3(B.x-step/2, B.y-step/2, B.z-step/2);
    vec3 V2 = vec3(B.x-step/2, B.y-step/2, B.z+step/2);
    vec3 V3 = vec3(B.x-step/2, B.y+step/2, B.z-step/2);
    vec3 V4 = vec3(B.x-step/2, B.y+step/2, B.z+step/2);
    vec3 V5 = vec3(B.x+step/2, B.y-step/2, B.z-step/2);
    vec3 V6 = vec3(B.x+step/2, B.y-step/2, B.z+step/2);
    vec3 V7 = vec3(B.x+step/2, B.y+step/2, B.z-step/2);
    vec3 V8 = vec3(B.x+step/2, B.y+step/2, B.z+step/2);*/
    //Left Side
    vec3 N = normalize(normalMatrix * vec3(-1, 0, 0));
    vec3 V[6];
    V[0] = V1;
    V[1] = V2;
    V[2] = V3;
    V[3] = V2;
    V[4] = V3;
    V[5] = V4;
    draw_face(N, C, V, false, B);
    //Back Side
    N = normalize(normalMatrix * vec3(0, 0, -1));
    V[0] = V1;
    V[1] = V3;
    V[2] = V5;
    V[3] = V3;
    V[4] = V5;
    V[5] = V7;
    draw_face(N, C, V, false, B);
    //Right Side
    N = normalize(normalMatrix * vec3(1, 0, 0));
    V[0] = V5;
    V[1] = V6;
    V[2] = V8;
    V[3] = V5;
    V[4] = V7;
    V[5] = V8;
    draw_face(N, C, V, false, B);
    //Front Side
    N = normalize(normalMatrix * vec3(0, 0, 1));
    V[0] = V2;
    V[1] = V6;
    V[2] = V8;
    V[3] = V2;
    V[4] = V4;
    V[5] = V8;
    draw_face(N, C, V, false, B);
    //Top Side
    N = normalize(normalMatrix * vec3(0, 1, 0));
    V[0] = V3;
    V[1] = V4;
    V[2] = V7;
    V[3] = V4;
    V[4] = V7;
    V[5] = V8;
    draw_face(N, C, V, true, B);
    // Bottom Side
    N = normalize(normalMatrix * vec3(0, -1, 0));
    V[0] = V1;
    V[1] = V5;
    V[2] = V6;
    V[3] = V1;
    V[4] = V2;
    V[5] = V6;
    draw_face(N, C, V, false, B);
}

void main( void )
{
    vec4 C = vec4(0);
    vec3 B = vec3(0);
    for (int i = 0; i < 3; ++i) {
        B += gl_in[i].gl_Position.xyz;
        C += vfrontColor[i];
    }
    C /= 3;
    B /= 3;
    B /= step;
    B = vec3(floor(B.x+0.5), floor(B.y+0.5), floor(B.z+0.5));
    B *= step;
    draw_cube(B, C);
}
