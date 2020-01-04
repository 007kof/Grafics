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

void main( void )
{
    vec3 N = vec3(0, 0, 0);
    for (int i = 0; i < 3; ++i) N += vNormal[i];
    N = N/3;
    vec3 translate = speed * time * N;
	for( int i = 0 ; i < 3 ; i++ )
	{
	    gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * (gl_in[i].gl_Position + vec4(translate, 0));
		EmitVertex();
	}
    EndPrimitive();
}
