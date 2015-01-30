#include "VertexPrimitive.h"

VertexPrimitive::VertexPrimitive(vector<Vertex> vertices): 
	vertices(vertices),
	transformMatrix(TransformMatrix()){}

VertexPrimitive::~VertexPrimitive(){}

/* Actions */
vector<Vertex> VertexPrimitive::transform(){
	Matrix4 tranformation = getTransformMatrix().transform();

	vector<Vertex> transformedVertices = getVertices();

	for (int i = 0; i < transformedVertices.size(); i++){
		transformedVertices[i].position = tranformation * transformedVertices[i].position;
	}

	return transformedVertices;
}

/* Getters */
TransformMatrix VertexPrimitive::getTransformMatrix(){
	return transformMatrix;
}

vector<Vertex> VertexPrimitive::getVertices(){
	return vertices;
}

/* Setters */
void VertexPrimitive::setTransformMatrix(TransformMatrix transformMatrix){
	VertexPrimitive::transformMatrix = transformMatrix;
}

void VertexPrimitive::setVertices(vector<Vertex> vertices){
	VertexPrimitive::vertices = vertices;
}
