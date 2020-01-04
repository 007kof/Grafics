#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float step = 0.1;

const vec4 light_grey = vec4(0.8, 0.8, 0.8, 1);

void draw_cube(vec3 B) {
    vec3 V1 = vec3(B.x-step, B.y-step, B.z-step);
    vec3 V2 = vec3(B.x-step, B.y-step, B.z+step);
    vec3 V3 = vec3(B.x-step, B.y+step, B.z-step);
    vec3 V4 = vec3(B.x-step, B.y+step, B.z+step);
    vec3 V5 = vec3(B.x+step, B.y-step, B.z-step);
    vec3 V6 = vec3(B.x+step, B.y-step, B.z+step);
    vec3 V7 = vec3(B.x+step, B.y+step, B.z-step);
    vec3 V8 = vec3(B.x+step, B.y+step, B.z+step);
    //Left Side
    vec3 N = normalize(normalMatrix * vec3(-1, 0, 0));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V1, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V2, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V3, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V2, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V3, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V4, 1.0);
    EmitVertex();
    EndPrimitive();
    //Back Side
    N = normalize(normalMatrix * vec3(0, 0, -1));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V1, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V3, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V5, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V3, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V5, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V7, 1.0);
    EmitVertex();
    EndPrimitive();
    //Right Side
    N = normalize(normalMatrix * vec3(1, 0, 0));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V5, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V6, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V8, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V5, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V7, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V8, 1.0);
    EmitVertex();
    EndPrimitive();
    //Front Side
    N = normalize(normalMatrix * vec3(0, 0, 1));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V2, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V6, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V8, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V2, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V4, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V8, 1.0);
    EmitVertex();
    EndPrimitive();
    //Top Side
    N = normalize(normalMatrix * vec3(0, 1, 0));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V3, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V4, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V7, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V4, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V7, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V8, 1.0);
    EmitVertex();
    EndPrimitive();
    // Bottom Side
    N = normalize(normalMatrix * vec3(0, -1, 0));
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V1, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V5, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V6, 1.0);
    EmitVertex();
    EndPrimitive();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V1, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V2, 1.0);
    EmitVertex();
    gfrontColor = light_grey * N.z;
    gl_Position = modelViewProjectionMatrix * vec4(V6, 1.0);
    EmitVertex();
    EndPrimitive();
    
}

void main( void )
{
    vec3 B = vec3(0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        B += gl_in[i].gl_Position.xyz;
    }
    B /= 3;
    B /= step;
    B.x = int(B.x);
    B.y = int(B.y);
    B.z = int(B.z);
    B *= step;
    draw_cube(B);
}
