#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vNormal[];
out vec4 gfrontColor;

uniform float d = 1;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

void main( void )
{
    for (int i = 0; i < 3; ++i) {
        gfrontColor = vfrontColor[i];
        gl_Position = modelViewProjectionMatrix * (gl_in[i].gl_Position + d);
        EmitVertex();
    }
    EndPrimitive();
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
}
