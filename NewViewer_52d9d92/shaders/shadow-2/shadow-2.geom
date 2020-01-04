#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 boundingBoxMin, boundingBoxMax;

const vec4 black = vec4(0, 0, 0, 1);
const vec4 cyan = vec4(0, 1, 1, 1);

void main( void )
{
    float y = boundingBoxMin.y;
    for (int i = 0; i < 3; ++i) {
        vec4 V = gl_in[i].gl_Position;
        V = vec4(V.x, y, V.z, V.w);
        gl_Position = modelViewProjectionMatrix * V;
        gfrontColor = black;
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
    if (gl_PrimitiveIDIn == 0) {
        float r = distance(boundingBoxMax,boundingBoxMin)/2;
        y -= 0.01;
        vec3 C = (boundingBoxMax + boundingBoxMin)/2;
        float x = C.x;
        float z = C.z;
        vec4 BottomLeft = vec4(x-r, y, z-r, 1);
        vec4 TopLeft = vec4(x-r, y, z+r, 1);
        vec4 BottomRight = vec4(x+r, y, z-r, 1);
        vec4 TopRight = vec4(x+r, y, z+r, 1);
        gfrontColor = cyan;
        gl_Position = modelViewProjectionMatrix * BottomLeft;
        EmitVertex();
        gl_Position = modelViewProjectionMatrix * TopLeft;
        EmitVertex();
        gl_Position = modelViewProjectionMatrix * TopRight;
        EmitVertex();
        EndPrimitive();
        gfrontColor = cyan;
        gl_Position = modelViewProjectionMatrix * BottomLeft;
        EmitVertex();
        gl_Position = modelViewProjectionMatrix * BottomRight;
        EmitVertex();
        gl_Position = modelViewProjectionMatrix * TopRight;
        EmitVertex();
        EndPrimitive();
    }
}
