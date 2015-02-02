#include "RenderBatch.h"

RenderBatch::RenderBatch(int maxVerticesCount, int renderType):
	maxVerticesCount(maxVerticesCount),
	renderType(renderType){
	
	//Make sure we are not creating to small of a RenderBatch, 1-4Mb is the optimal size
	if (maxVerticesCount < 1000){
		fprintf(stdout, "Render Batch Error: maxVerticesCount must be over 1000 was %i(code: %i)", maxVerticesCount, ERROR_RENDER_BATCH_MIN_VERTICES_LOW);
	}

	glGetError();

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, maxVerticesCount * sizeof(Vertex), nullptr, GL_STREAM_DRAW);
}

RenderBatch::~RenderBatch(){}//TODO Implement RenderBatch::~RenderBatch()

/* Actions */
void RenderBatch::render(){
	
}