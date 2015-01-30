#ifndef VECTOR3_HEADER_GUARD
#define VECTOR3_HEADER_GUARD

#include <GL\glew.h>
#include <iostream>

#include "Errors.h"

struct Vector3{
	GLfloat x;
	GLfloat y;
	GLfloat z;

	Vector3() : x(0), y(0), z(0){}
	Vector3(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z){}

	GLfloat get(int index){
		if (index == 0){
			return x;
		}
		else if (index == 1){
			return y;
		}
		else if (index == 2){
			return z;
		}
		else{
			fprintf(stdout, "Vector4 get() Error: Index %i is invalid(code: %i)", index, ERROR_VECTOR3_INDEX_NOT_FOUND);
			return x;
		}
	}

	Vector3 operator * (Vector3 &factor){
		return Vector3(
			x * factor.x,
			y * factor.y,
			z * factor.z);
	}

	GLfloat sum(){
		return x + y + z;
	}
};

#endif
