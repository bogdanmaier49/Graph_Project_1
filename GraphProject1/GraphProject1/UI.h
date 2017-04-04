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
	Edge readEdge(const char* msg);
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
	void printOutboundEdges();
	void printInboundEdges();

	void addVertex();
	void removeVertex();
	void addEdge();
	void removeEdge();
	void changeEdgeData();

	void start();

	void printVertexArray(DynamicArray<Vertex>* arr);
};

