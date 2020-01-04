#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform float time;
uniform mat4 modelViewProjectionMatrix;

const float speed = 100.0;

void main( void )
{
    if (gl_PrimitiveIDIn < int(speed * time)) {
	    for( int i = 0 ; i < 3 ; i++ )
	    {
		    gfrontColor = vfrontColor[i];
		    gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		    EmitVertex();
	    }
        EndPrimitive();
    }
}
