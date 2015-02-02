#version 330 core

in vec4 vertexPos;
in vec4 vertexColor;

in mat4 viewTranslation;
in mat4 viewRotation;
in mat4 viewScale;

out vec4 outColor;

void main(){
	mat4 viewTransformed = viewTranslation * viewRotation * viewScale;
	gl_Position = viewTransformed * vertexPos;

	outColor = vertexColor;
}