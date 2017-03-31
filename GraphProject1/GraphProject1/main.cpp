#include "Tests.h"
#include "Graph.h"
#include <stdio.h>
#include <fstream>

Graph* readGraph(const char* fileName)
{
	std::ifstream f(fileName);

	int numberOfVerts = 0;
	int numberOfEdges = 0;

	f >> numberOfVerts;
	f >> numberOfEdges;

	Graph *g = new Graph();

	// Add Vertices to the graph
	for (int i = 0; i < numberOfVerts; i++)
	{
		Vertex v = { i };
		g->addVertex(v);
	}

	// Add edges to the graph
	for (int i = 0; i < numberOfEdges; i++)
	{
		int _source = 0;
		int _target = 0;
		int _cost = 0;

		f >> _source;
		f >> _target;
		f >> _cost;

		Vertex* source = new Vertex(_source);
		Vertex* target = new Vertex(_target);

		Edge e = { i, source, target };
		e.setCost(_cost);

		g->addEdge(e);
	}


	f.close();

	return g;
}

void printGraph(Graph* g) {
	for (int i = 0; i < g->getNumberOfEdges(); i++)
	{
		Edge e = g->getEdge(i);
		std::cout << "Vert: " << i << ", " << e.getSourceVertex()->getIndex() << " " << e.getTargetVertex()->getIndex() << " " << e.getCost() << "\n";
	}
}

int main()
{
	// TestDynamicArray();
	// TestGraph();

	std::cout << sizeof(Vertex) + sizeof(Edge) << " \n";
	Graph* g = readGraph("1m.txt");

	printGraph(g);

	getchar();
	return 0;
}