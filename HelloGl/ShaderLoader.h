#ifndef SHADER_LOADER_DEF_GUARD
#define SHADER_LOADER_DEF_GUARD

#include <string>
#include <fstream>
#include <GL\glew.h>

#include "Errors.h"

using namespace std;

class ShaderLoader{
	string fileLocation;
public:
	ShaderLoader(string fileLocation);
	int load(GLuint *shader);
};

#endif