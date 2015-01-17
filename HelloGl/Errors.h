#ifndef ERRORS_DEF_GUARD
#define ERRORS_DEF_GUARD

/*
0-99    General errors
100-199 File errors
200-299 Shader errors
*/
#define ERROR_OK 0
#define ERROR_FAIL 1
#define ERROR_GLFW_INIT_FAIL 2
#define ERROR_GLEW_INIT_FAIL 3

#define ERROR_FILE_NOT_FOUND 100
#define ERROR_FILE_EMPTY 101

#define ERROR_SHADERS_LOAD_FAIL 200
#define ERROR_SHADER_CHECK_FAIL 201
#define ERROR_SHADER_LINK_FAIL 202
#endif