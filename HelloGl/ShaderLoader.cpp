#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(string fileLocation): fileLocation(fileLocation){}

int ShaderLoader::load(GLuint *shader){
	GLchar** shaderSource;
	ifstream file;

	//Open file
	file.open(fileLocation, ios::in);
	if (!file){
		return ERROR_FILE_NOT_FOUND;
	}

	//Get file length
	unsigned long shaderSourceLen;
	file.tellg();
	file.seekg(0, ios::end);
	shaderSourceLen = file.tellg();
	file.seekg(ios::beg);

	if (shaderSourceLen == 0){
		return ERROR_FILE_EMPTY;
	}

	//Fill shaderSource)
	*shaderSource = (GLubyte*) new char[shaderSourceLen + 1];
	*shaderSource[shaderSourceLen] = 0;
	unsigned int lineNum = 0;
	while (file.good()){
		*shaderSource[lineNum] = file.get();
		if (!file.eof()){
			lineNum++;
		}
	}

	*shaderSource[lineNum] = 0;

	file.close();
	
	//Set shader source
	glShaderSource(*shader, 1, shaderSource, (const GLint*) shaderSourceLen);

	return ERROR_OK;
}