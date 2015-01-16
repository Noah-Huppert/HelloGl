#include "ShaderLoader.h"

int ShaderLoader::load(char *filePath, GLuint *shader){
	//Load shader file
	string shaderFileContents;
	ifstream shaderFile(filePath, ios::in);

	if (shaderFile.is_open()){
		string line;
		while (getline(shaderFile, line)){
			shaderFileContents += "\n" + line;
		}
		shaderFile.close();
	}

	//Compile shader
	const char *shaderSourcePointer = shaderFileContents.c_str();
	glShaderSource(*shader, 1, &shaderSourcePointer, NULL);
	glCompileShader(*shader);

	//Check shader
	GLint shaderCheckResult = GL_FALSE;
	int infoLogLength;
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &shaderCheckResult);
	glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &infoLogLength);
	vector<char> shaderErrorMessage(infoLogLength);
	glGetShaderInfoLog(*shader, infoLogLength, NULL, &shaderErrorMessage[0]);

	fprintf(stdout, "%s\n", &shaderErrorMessage[0]);

	//Link
	GLuint programId = glCreateProgram();
	glAttachShader(programId, *shader);
	glLinkProgram(programId);

	glGetProgramiv(programId, GL_LINK_STATUS, &shaderCheckResult);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	vector<char> programErrorMessage(max(infoLogLength, int(1)));
	glGetProgramInfoLog(programId, infoLogLength, NULL, &programErrorMessage[0]);

	fprintf(stdout, "%s\n", &programErrorMessage[0]);

	return programId;
}