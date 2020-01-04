#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec3 vNormal[];
out vec3 gNormal;
out vec3 gPos;

uniform float d = 0.1;
uniform mat4 modelViewProjectionMatrix;

void draw_vertex(vec3 V, vec3 N) {
    gPos = V;
    gNormal = N;
    gl_Position = modelViewProjectionMatrix * vec4(V, 1);
    EmitVertex();
}

void draw_figure(vec3 V[6], vec3 N) {
    // Bottom Face
    draw_vertex(V[0], -N);
    draw_vertex(V[1], -N);
    draw_vertex(V[2], -N);
    EndPrimitive();
    /*// Top Face
    draw_vertex(V[3], N);
    draw_vertex(V[4], N);
    draw_vertex(V[5], N);
    EndPrimitive();*/
    // Lateral Face 1
    vec3 a = V[1] - V[0];
    vec3 b = V[3] - V[0];
    N = cross(a, b)/length(cross(a, b));
    draw_vertex(V[0], N);
    draw_vertex(V[1], N);
    draw_vertex(V[3], N);
    draw_vertex(V[4], N);
    EndPrimitive();
    // Lateral Face 2
    a = V[2] - V[1];
    b = V[4] - V[1];
    N = cross(a, b)/length(cross(a, b));
    draw_vertex(V[1], N);
    draw_vertex(V[2], N);
    draw_vertex(V[4], N);
    draw_vertex(V[5], N);
    EndPrimitive();
    // Lateral Face 3
    a = V[0] - V[2];
    b = V[5] - V[2];
    N = cross(a, b)/length(cross(a, b));
    draw_vertex(V[0], N);
    draw_vertex(V[2], N);
    draw_vertex(V[3], N);
    draw_vertex(V[5], N);
    EndPrimitive();
}

void main( void )
{
    vec3 N = vec3(0);
    for (int i = 0; i < 3; ++i) N += vNormal[i];
    N = normalize(N/3);
    vec3 V0 = gl_in[0].gl_Position.xyz;
    vec3 V1 = gl_in[1].gl_Position.xyz;
    vec3 V2 = gl_in[2].gl_Position.xyz;
    vec3 V3 = V0 + d*N;
    vec3 V4 = V1 + d*N;
    vec3 V5 = V2 + d*N;
    //if (gl_PrimitiveIDIn != 0) return;
    vec3 V[6];
    V[0] = V0;
    V[1] = V1;
    V[2] = V2;
    V[3] = V3;
    V[4] = V4;
    V[5] = V5;
    draw_figure(V, N);
}
