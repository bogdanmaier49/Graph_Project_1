#pragma once

#include "Graph.h"
#include <iostream>
#include <Windows.h>

class UI
{
private:
	Graph* graph;

	int readInt(const char* msg);
	Vertex readVertex(const char* msg);
	void cls();

public:
	UI(Graph* graph);
	~UI();

	void printGraph();
	void printNumberOfVertices();
	void printNumberOfEdges();
	void printHasEdge();
	void printInDegree();
	void printOutDegree();
	void printEdgeEndPoints();

	void start();

	void printVertexArray(DynamicArray<Vertex>* arr);
};

