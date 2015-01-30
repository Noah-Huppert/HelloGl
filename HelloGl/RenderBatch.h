#ifndef RENDER_BATCH_HEADER_GUARD
#define RENDER_BATCH_HEADER_GUARD

#include <iostream>
#include "Errors.h"

class RenderBatch{
private:
	int maxVerticesCount;

	int vertexBuffer;
	int renderType;

public:
	RenderBatch(int maxVerticesCount, int renderType);
	~RenderBatch();

	/* Actions */
	void render();
};

#endif
