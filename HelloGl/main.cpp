#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

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
		return 1;
	}

	//Setup context
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGl", NULL, NULL);
	if (!window){
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	//Bind Gl
	GLenum glewInitErr = glewInit();
	if (glewInitErr != GLEW_OK){
		fprintf(stdout, "Glew Error: %s\n", glewGetErrorString(glewInitErr));
	}

	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}