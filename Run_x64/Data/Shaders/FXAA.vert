#version 430 core


in vec3 inPosition;
in vec2 inUV0;

out vec2 passUV0;

void main( void ) {

	passUV0		= vec2(inUV0.x, 1.f - inUV0.y);
	vec4 pos	= vec4(inPosition, 1.0f);
	gl_Position = vec4( pos );
}