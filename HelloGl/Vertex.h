#ifndef VERTEX_HEADER_GUARD
#define VERTEX_HEADER_GUARD

#include "Vector4.h"

struct Vertex{
	Vector4 position;
	Vector4 color;

	Vertex(Vector4 position, Vector4 color) : position(position), color(color){}
};

#endif
