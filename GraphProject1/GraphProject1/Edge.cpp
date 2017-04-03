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
	if (e.getID() == this->getID())
		return true;
	return false;
}
