#include "RenderBatch.h"

RenderBatch::RenderBatch(int maxVerticesCount, int renderType):
	maxVerticesCount(maxVerticesCount),
	renderType(renderType){
	
	//Make sure we are not creating to small of a RenderBatch, 1-4Mb is the optimal size
	if (maxVerticesCount < 1000){
		fprintf(stdout, "Render Batch Error: maxVerticesCount must be over 1000 was %i(code: %i)", maxVerticesCount, ERROR_RENDER_BATCH_MIN_VERTICES_LOW);
	}

	//TODO Implement the rest of RenderBatch::RenderBatch()
}

RenderBatch::~RenderBatch(){}//TODO Implement RenderBatch::~RenderBatch()

/* Actions */
void RenderBatch::render(){}//TODO Implement RenderBatch::render()