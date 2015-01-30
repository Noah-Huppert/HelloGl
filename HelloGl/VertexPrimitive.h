#ifndef VERTEX_PRIMITIVE_HEADER_GUARD
#define VERTEX_PRIMITIVE_HEADER_GUARD

#include "vector"
#include "TransformMatrix.h"
#include "Vertex.h"

using namespace std;

class VertexPrimitive{
private:
	TransformMatrix transformMatrix;
	vector<Vertex> vertices;

public:
	VertexPrimitive(vector<Vertex> vertices);
	~VertexPrimitive();

	/* Actions */
	vector<Vertex> transform();

	/* Getters */
	TransformMatrix getTransformMatrix();
	vector<Vertex> getVertices();

	/* Setters */
	void setTransformMatrix(TransformMatrix transformMatrix);
	void setVertices(vector<Vertex> vertices);
};

#endif
