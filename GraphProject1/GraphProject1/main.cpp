#include "Tests.h"
#include "Graph.h"
#include <stdio.h>
#include <fstream>
#include "UI.h"

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

int main()
{
	// TestDynamicArray();
	// TestGraph();
	// getchar();
	
	std::cout << "Loading graph ... \n";
	Graph* g = readGraph("4k.txt");

	UI* ui = new UI(g);
	ui->start();
	delete ui;

	
	
	return 0;
}