#include "Vertex.h"



Vertex::Vertex(int index)
{
	this->index = index;
}

bool Vertex::operator==(Vertex v)
{
	if (this->index == v.index)
		return true;
	return false;
}