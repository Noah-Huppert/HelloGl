#ifndef TRANSFORM_MATRIX_HEADER_GUARD
#define TRANFORM_MATRIX_HEADER_GUARD

#include "Matrix4.h"

struct TransformMatrix{
	Matrix4 translationMatrix;
	Matrix4 rotationMatrix;
	Matrix4 scaleMatrix;

	TransformMatrix() : 
		translationMatrix(Matrix4(1)),
		rotationMatrix(Matrix4(1)),
		scaleMatrix(Matrix4(1)){}

	TransformMatrix(Matrix4 translationMatrix, Matrix4 rotationMatrix, Matrix4 scaleMatrix):
		translationMatrix(translationMatrix),
		rotationMatrix(rotationMatrix),
		scaleMatrix(scaleMatrix){}

	Matrix4 transform(){
		return translationMatrix * rotationMatrix * scaleMatrix;
	}
};

#endif
