#pragma once

#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include <iostream>

class UI
{
	Graph* graph;

	Vertex readVertex(const char* msg);
	Edge readEdge(const char* edge);

	void cls() {
		system("@cls||clear");
	}


public:
	UI(Graph* graph) : graph(graph) {};
	~UI() { delete graph; };

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

	void UI::printVertexArray(std::vector<Vertex>* arr);

	void printEdgeArr(std::vector<Edge>* arr)
	{
		for (int i = 0; i < arr->size(); i++)
			std::cout << " " << arr->at(i).getSource().getValue() << " " << arr->at(i).getTarget().getValue() << " " << arr->at(i).getValue() << std::endl;
		std::cout << std::endl;
	}

	void start();

};


