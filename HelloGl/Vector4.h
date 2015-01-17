#ifndef VECTOR4_DEF_GUARD
#define VECTOR4_DEF_GUARD

#define VECTOR_POSITION 1
#define VECTOR_DIRECTION 0

#include <GL\glew.h>

struct Vector4{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLint w;

	Vector4(GLfloat x, GLfloat y, GLfloat z, GLint w) : x(x), y(y), z(z), w(w){}

	Vector4 operator * (Vector4 &factor){
		x *= factor.x;
		y *= factor.y;
		z *= factor.z;
		w *= factor.w;
		return *this;
	}

	Vector4 operator *= (Vector4 &factor){
		return *this * factor;
	}

	GLfloat sum(){
		return x + y + z + w;
	}
};

#endif