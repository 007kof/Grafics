#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vNormal[];
out vec4 gfrontColor;

uniform float time;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

const float speed = 0.5;
const float angSpeed = 8.0;

void main( void )
{
    vec3 N = vec3(0, 0, 0);
    vec3 B = vec3(0, 0, 0);
    for (int i = 0; i < 3; ++i) {
        B += gl_in[i].gl_Position.xyz;
        N += vNormal[i];
    }
    N /= 3;
    B /= 3;
    vec3 translate = speed * time * N;
    float angle = angSpeed * time;
    mat3 R = mat3(vec3(cos(angle), sin(angle), 0), vec3(-sin(angle), cos(angle), 0), vec3(0, 0, 1));
	for( int i = 0 ; i < 3 ; i++ )
	{
	    gfrontColor = vfrontColor[i];
	    vec3 V = R * (gl_in[i].gl_Position.xyz - B);
	    V += translate + B;
		gl_Position = modelViewProjectionMatrix * vec4(V, 1.0);
		EmitVertex();
	}
    EndPrimitive();
}
