#ifndef SHADER_LOADER_DEF_GUARD
#define SHADER_LOADER_DEF_GUARD

#include <GL\glew.h>
#include <fstream>
#include <string>
#include <vector>
#include <minmax.h>
#include "Errors.h"

using namespace std;

class ShaderLoader{
public:
	static int create(GLenum shaderType, char *filePath, GLuint *shaderProgramId);
	static int load(char *filePath, GLuint *shader, GLuint *shaderProgramId);
};

#endif