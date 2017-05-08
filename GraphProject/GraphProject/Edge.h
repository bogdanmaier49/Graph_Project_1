#pragma once

#include "Vertex.h"

class Edge
{
	Vertex source;
	Vertex target;
	int value = 0;
public:
	Edge(Vertex source, Vertex target) : source(source), target(target) {};

	Vertex getTarget() { return this->target; }
	Vertex getSource() { return this->source; }
	void setSource(Vertex source) { this->source = source; }
	void setTarget(Vertex target) { this->target = target; }
	
	int getValue() { return value; }
	void setValue(int value) { this->value = value; }

	bool operator== (Edge other)
	{
		if (this->getSource() == other.getSource() &&
			this->getTarget() == other.getTarget())
			return true;

		return false;
	}
};

#define NULL_EDGE Edge(NULL, NULL)
