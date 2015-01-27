#ifndef VERTEX_MANAGER_HEADER_GUARD
#define VERTEX_MANAGER_HEADER_GUARD

#include "Matrix4.h"
#include "Vector4.h"

class VertexManager{
private:
	Matrix4 globalTransformationMatrix;
	Matrix4 globalScaleMatrix;
	Matrix4 identityMatrix;

	Vector4 vertices[];

public:
	/* Getters */
	Matrix4 getGlobalTransformationMatrix();
	Matrix4 getGlobalScaleMatrix();
	Matrix4 getIndentityMatrix();
	Vector4* getVertices();
	Vector4* getTransformedVertices();

	/* Setters */
	void setGlobalTransformationMatrix(Matrix4 globalTransformationMatrix);
	void setGlobalScaleMatrix(Matrix4 globalScaleMatrix);
	void setIdentityMatrix(Matrix4 identityMatrix);
	void setVertices(Vector4 vertices);
};

#endif