#ifndef VERTEX_MANAGER_HEADER_GUARD
#define VERTEX_MANAGER_HEADER_GUARD

#include "Matrix4.h"
#include "Vector4.h"
#include "vector"

using namespace std;

class VertexManager{
private:
	Matrix4 globalTranslationMatrix;
	Matrix4 globalRotationMatrix;
	Matrix4 globalScaleMatrix;
	Matrix4 identityMatrix;

	Matrix4 viewMatrix;

	vector<Vector4> vertices;

public:
	VertexManager();

	/* Getters */
	Matrix4 getGlobalTranslationMatrix();
	Matrix4 getGlobalRotationMatrix();
	Matrix4 getGlobalScaleMatrix();
	Matrix4 getIndentityMatrix();
	vector<Vector4> getVertices();
	vector<Vector4> getTransformedVertices();

	/* Setters */
	void setGlobalTranslationMatrix(Matrix4 globalTransformationMatrix);
	void setGlobalRotationMatrix(Matrix4 globalRotationMatrix);
	void setGlobalScaleMatrix(Matrix4 globalScaleMatrix);
	void setIdentityMatrix(Matrix4 identityMatrix);
	void setVertices(vector<Vector4> vertices);
};

#endif