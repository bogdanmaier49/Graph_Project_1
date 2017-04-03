#pragma once

#include "DynamicArray.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>

class Graph
{
private:
	DynamicArray<Vertex>	*verts;
	DynamicArray<Edge>		*edges;
public: 
	Graph();
	~Graph();

	void addVertex(Vertex v);
	void removeVertex(Vertex v);
	Vertex getVertex(unsigned int index);

	void addEdge(Edge e);
	void removeEdge(Edge e);
	Edge getEdge(unsigned int index);

	int getNumberOfVerts();
	int getNumberOfEdges();
	int hasEdge(Vertex*, Vertex*);
	int getInDegree(Vertex*);
	int getOutDegree(Vertex*);
	DynamicArray<int>* getOutboundEdges(Vertex*);
	DynamicArray<int>* getInboundEdges(Vertex*);
	DynamicArray<Vertex> *getEdgeEndPoints(int EdgeID);

	void setEdgeValue(unsigned int, int);
	int getEdgeValue(Edge);
};

