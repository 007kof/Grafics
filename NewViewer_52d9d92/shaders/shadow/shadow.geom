#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform vec3 boundingBoxMin;
uniform mat4 modelViewProjectionMatrix;

const vec4 black = vec4(0, 0, 0, 1);

void main( void )
{
    float y = boundingBoxMin.y;
    for (int i = 0; i < 3; ++i) {
        vec4 V = gl_in[i].gl_Position;
        V = vec4(V.x, y, V.z, V.w);
        gl_Position = modelViewProjectionMatrix * V;
        EmitVertex();
    }
    gfrontColor = black;
    EndPrimitive();
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
}
