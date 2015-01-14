#include <Windows.h>
#include <GLFW\glfw3.h>

#include <stdio.h>
#include <stdlib.h>

void error_callback(int error, const char* desc){
	fputs(desc, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main(){
	glfwSetErrorCallback(error_callback);

	if (glfwInit == 0){//glfwInit returns 0 if failed, and non 0 if it succeeds
		exit(EXIT_FAILURE);
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello OpenGl", NULL, NULL);//Returns NULL if fail
	if (window == NULL){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	int width, heigth;

	while (glfwWindowShouldClose(window) == false){

	}

	glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}