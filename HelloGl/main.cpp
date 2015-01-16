#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "ShaderLoader.h"

using namespace std;

void error_callback(int error, const char* desc){
	fprintf(stdout, "GLFW Error: %s\n", desc);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main(){
	//Init GLFW
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()){
		return ERROR_GLFW_INIT_FAIL;
	}

	//Setup context
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGl", NULL, NULL);
	if (!window){
		glfwTerminate();
		return ERROR_GLFW_INIT_FAIL;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	//Bind Gl
	GLenum glewInitErr = glewInit();
	if (glewInitErr != GLEW_OK){
		fprintf(stdout, "Glew Error: %s\n", glewGetErrorString(glewInitErr));
		return ERROR_GLEW_INIT_FAIL;
	}

	GLuint vertexShader;
	GLuint fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	ShaderLoader *vertexShaderLoader = new ShaderLoader("simple_vertex_shader.glsl");
	vertexShaderLoader->load(&vertexShader);

	while (!glfwWindowShouldClose(window)){
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return ERROR_OK;
}