#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform mat4 modelViewMatrix, modelViewProjectionMatrix;

const float areamax = 0.0005;
const vec4 red = vec4(1, 0, 0, 1);
const vec4 yellow = vec4(1, 1, 0, 1);

void main( void )
{
    vec4 V1 = modelViewMatrix * gl_in[0].gl_Position;
    vec4 V2 = modelViewMatrix * gl_in[1].gl_Position;
    vec4 V3 = modelViewMatrix * gl_in[2].gl_Position;
    vec3 u = V2.xyz - V1.xyz;
    vec3 v = V3.xyz - V1.xyz;
    vec3 res = cross(u,v);
    float area = sqrt(res.x*res.x + res.y*res.y + res.z*res.z)/(2*areamax);
    vec4 color = mix(red, yellow, area);
    for (int i = 0; i < 3; ++i) {
        gfrontColor = color;
        gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
        EmitVertex();
    }
    EndPrimitive();
	/*for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();*/
}
