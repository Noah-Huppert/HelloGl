#ifndef VECTOR3_DEF_GUARD
#define VECTOR3_DEF_GUARD

#include <GL\glew.h>

struct Vector3{
	GLfloat x;
	GLfloat y;
	GLfloat z;

	Vector3(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z){}
};

#endif