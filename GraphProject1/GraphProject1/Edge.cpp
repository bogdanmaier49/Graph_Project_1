#include "Edge.h"



Edge::Edge(int id, Vertex* source, Vertex* target)
{
	this->id = id;
	this->source = source;
	this->target = target;
}

Edge::~Edge()
{
}

bool Edge::operator==(Edge e)
{
	if (this->source == e.target && this->target == e.target && this->id==e.id)
		return true;
	return false;
}