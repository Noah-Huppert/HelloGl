#ifndef RENDER_CAMERA_HEADER_GUARD
#define RENDER_CAMERA_HEADER_GUARD

#include "TransformMatrix.h"

class RenderCamera{
private:
	TransformMatrix transformMatrix;

public:
	RenderCamera();
	~RenderCamera();
};

#endif
