#include "VertexManager.h"

VertexManager::VertexManager(){
	
}


/* Getters */
Matrix4 VertexManager::getGlobalTranslationMatrix(){
	return globalTranslationMatrix;
}

Matrix4 VertexManager::getGlobalRotationMatrix(){
	return globalRotationMatrix;
}


Matrix4 VertexManager::getGlobalScaleMatrix(){
	return globalScaleMatrix;
}

Matrix4 VertexManager::getIndentityMatrix(){
	return identityMatrix;
}

vector<Vector4> VertexManager::getVertices(){
	return vertices;
}


vector<Vector4> VertexManager::getTransformedVertices(){
	vector<Vector4> tranformedVertices = getVertices();

	for (int i = 0; i < tranformedVertices.size(); i++){
		Vector4 transformedVertex = getGlobalTranslationMatrix() * getGlobalRotationMatrix() * getGlobalScaleMatrix() * tranformedVertices[i];
	}

	return tranformedVertices;
}

/* Setters */
void VertexManager::setGlobalTranslationMatrix(Matrix4 globalTransformationMatrix){
	VertexManager::globalTranslationMatrix = globalTransformationMatrix;
}

void VertexManager::setGlobalRotationMatrix(Matrix4 globalRotationMatrix){
	VertexManager::globalRotationMatrix = globalRotationMatrix;
}


void VertexManager::setGlobalScaleMatrix(Matrix4 globalScaleMatrix){
	VertexManager::globalScaleMatrix = globalScaleMatrix;
}

void VertexManager::setIdentityMatrix(Matrix4 identityMatrix){
	VertexManager::identityMatrix = identityMatrix;
}

void VertexManager::setVertices(vector<Vector4> vertices){
	VertexManager::vertices = vertices;
}