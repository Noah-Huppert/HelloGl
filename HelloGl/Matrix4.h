#ifndef MATRIX4_DEF_GUARD
#define MATRIX4_DEF_GUARD

#include "Vector4.h"

struct Matrix4{
	Vector4 x;
	Vector4 y;
	Vector4 z;
	Vector4 w;

	Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 w) : x(x), y(y), z(z), w(w){}

	Vector4 operator * (Vector4 &vector){
		x *= vector;
		y *= vector;
		z *= vector;
		w *= vector;
		return Vector4::Vector4(x.sum(), y.sum(), z.sum(), w.sum());
	}
};

#endif