#version 430

uniform mat4 gModel;
uniform mat4 gView;
uniform mat4 gProj;


in vec3 inPosition;
in vec4 inColor;
in vec2 inUV0;
in vec3 inNormal;
in vec3 inTangent;
in vec3 inBitangent;


out vec4 passColor;
out vec2 passUV0;
out vec3 passPosition;
out vec3 passNormal;
out vec3 passTangent;
out vec3 passBitangent;

out vec3 passCameraPosition;


void main ( void ) {

	passColor		= inColor;
	passUV0			= inUV0;

	vec4 pos		= vec4(inPosition, 1.0f);
	passPosition	= (vec4(inPosition, 1.f)	* gModel * gView).xyz;
	passNormal		= (vec4(inNormal, 0.f)		* gModel * gView).xyz;
	passTangent		= (vec4(inTangent, 0.f)		* gModel).xyz;
	passBitangent	= (vec4(inBitangent, 0.f)	* gModel).xyz;	

	gl_Position		= vec4(inPosition, 1.0f) * gModel * gView * gProj;
}