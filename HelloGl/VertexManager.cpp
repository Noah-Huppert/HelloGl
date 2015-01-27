#include "VertexManager.h"

/* Getters */
Matrix4 VertexManager::getGlobalTransformationMatrix(){
	return globalTransformationMatrix;
}

Matrix4 VertexManager::getGlobalScaleMatrix(){
	return globalScaleMatrix;
}

Matrix4 VertexManager::getIndentityMatrix(){
	return identityMatrix;
}

Vector4* VertexManager::getVertices(){
	return vertices;
}


Vector4* VertexManager::getTransformedVertices(){
	return nullptr;
}

/* Setters */
void VertexManager::setGlobalTransformationMatrix(Matrix4 globalTransformationMatrix){
	VertexManager::globalTransformationMatrix = globalTransformationMatrix;
}

void VertexManager::setGlobalScaleMatrix(Matrix4 globalScaleMatrix){
	VertexManager::globalScaleMatrix = globalScaleMatrix;
}

void VertexManager::setIdentityMatrix(Matrix4 identityMatrix){
	VertexManager::identityMatrix = identityMatrix;
}

void VertexManager::setVertices(Vector4 vertices){
	*VertexManager::vertices = vertices;
}


