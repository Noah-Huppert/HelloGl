#ifndef VECTOR4_DEF_GUARD
#define VECTOR4_DEF_GUARD

#define VECTOR_POSITION 1
#define VECTOR_DIRECTION 0

#include <GL\glew.h>
#include <iostream>

#include "Errors.h"

struct Vector4 {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLint w;

	Vector4() : x(0), y(0), z(0), w(0){}
	Vector4(GLfloat x, GLfloat y, GLfloat z, GLint w) : x(x), y(y), z(z), w(w){}

	GLfloat get(int index){
		if (index == 0){
			return x;
		} else if (index == 1){
			return y;
		} else if (index == 2){
			return z;	
		} else if (index == 3){
			return w;
		} else{
			fprintf(stdout, "Vector4 get() Error: Index %i is invalid(code: %i)", index, ERROR_VECTOR4_INDEX_NOT_FOUND);
			return x;
		}
	}

	Vector4 operator * (Vector4 &factor){
		return Vector4(
			x * factor.x,
			y * factor.y,
			z * factor.z,
			w * factor.w);
	}

	Vector4 operator *= (Vector4 &factor){
		return *this * factor;
	}

	GLfloat sum(){
		return x + y + z + w;
	}
};

#endif