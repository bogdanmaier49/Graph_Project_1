#pragma once

#include "Vertex.h"

class Edge
{

private:

	int id;
	Vertex* source;
	Vertex* target;
	int cost;

public:
	Edge(int id, Vertex* source, Vertex* target);
	Edge() {}
	~Edge();

	bool operator==(Edge);

	inline int getID() const { return id;  }
	inline int getCost() const { return cost; }
	inline Vertex* getSourceVertex() const { return source; }
	inline Vertex* getTargetVertex() const { return target; }
	inline void setCost(int newCost) { this->cost = newCost; }
	inline int getCost() { return this->cost; }
};

