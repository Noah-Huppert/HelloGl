#include "ShaderLoader.h"

int ShaderLoader::create(GLenum shaderType, char *filePath, GLuint *shaderProgramId){
	GLuint shader = glCreateShader(shaderType);
	int loadStatus = ShaderLoader::load(filePath, &shader, shaderProgramId);
	glDeleteShader(shader);
	return loadStatus;
}

int ShaderLoader::load(char *filePath, GLuint *shader, GLuint *shaderProgramId){
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

	if (shaderErrorMessage[0] != NULL){
		fprintf(stdout, "Check Shader Error\n%s\n", &shaderErrorMessage[0]);
		return ERROR_SHADER_CHECK_FAIL;
	}

	//Link
	GLuint programId = glCreateProgram();
	glAttachShader(programId, *shader);
	glLinkProgram(programId);

	glGetProgramiv(programId, GL_LINK_STATUS, &shaderCheckResult);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	vector<char> programErrorMessage(max(infoLogLength, int(1)));
	glGetProgramInfoLog(programId, infoLogLength, NULL, &programErrorMessage[0]);

	if (programErrorMessage[0] != NULL){
		fprintf(stdout, "Link Error\n%s\n", &programErrorMessage[0]);
		return ERROR_SHADER_LINK_FAIL;
	}

	*shaderProgramId = programId;

	return ERROR_OK;
}