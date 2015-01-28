#ifndef MATRIX4_DEF_GUARD
#define MATRIX4_DEF_GUARD

#include "Vector4.h"

struct Matrix4{
	Vector4 x;
	Vector4 y;
	Vector4 z;
	Vector4 w;

	Matrix4() : x(Vector4()), y(Vector4()), z(Vector4()), w(Vector4()){}
	Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 w) : x(x), y(y), z(z), w(w){}

	Vector4 getColumn(int colNum){
		return Vector4(x.get(colNum), y.get(colNum), z.get(colNum), w.get(colNum));
	}

	Matrix4 operator * (Matrix4 &matrix){
		return Matrix4(
			x * matrix.getColumn(0),
			y * matrix.getColumn(1),
			z * matrix.getColumn(2),
			w * matrix.getColumn(3));
	}

	Vector4 operator * (Vector4 &vector){
		return Vector4(
			(x * vector).sum(),
			(y * vector).sum(),
			(z * vector).sum(),
			(w * vector).sum());
	}
};

#endif