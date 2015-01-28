#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Errors.h"
#include "Vector4.h"
#include "Matrix4.h"
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

	//Setup Vertex arrays
	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	Vector4 vertexBufferData[] = {
		Vector4(-1.0f, -1.0f, 0.0f, VECTOR_POSITION),
		Vector4(1.0f, -1.0f, 0.0f, VECTOR_POSITION),
		Vector4(0.0f, 1.0f, 0.0f, VECTOR_POSITION)
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	GLuint vertexShaderId = NULL;
	GLuint fragmentShaderId = NULL;

	int vertexShaderLoadError = ShaderLoader::create(GL_VERTEX_SHADER, "simple_vertex_shader.glsl", &vertexShaderId);
	int fragmentShaderLoadError = ShaderLoader::create(GL_FRAGMENT_SHADER, "simple_fragment_shader.glsl", &fragmentShaderId);

	if (vertexShaderLoadError != ERROR_OK || fragmentShaderLoadError != ERROR_OK){
		fprintf(stdout, "Shaders failed to load, Vertex Error: %i, Fragment Error: %i", vertexShaderLoadError, fragmentShaderLoadError);
		return ERROR_SHADERS_LOAD_FAIL;
	}

	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(vertexShaderId);
		glUseProgram(fragmentShaderId);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return ERROR_OK;
}