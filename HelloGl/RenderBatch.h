#ifndef RENDER_BATCH_HEADER_GUARD
#define RENDER_BATCH_HEADER_GUARD

#include <iostream>
#include <GL\glew.h>
#include "Errors.h"
#include "Vertex.h"

class RenderBatch{
private:
	int maxVerticesCount;

	unsigned vertexArray;
	unsigned vertexBuffer;
	int renderType;

public:
	RenderBatch(int maxVerticesCount, int renderType);
	~RenderBatch();

	/* Actions */
	void render();
};

#endif
