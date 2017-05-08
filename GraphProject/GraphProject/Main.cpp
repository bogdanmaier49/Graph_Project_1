#include "Graph.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include "UI.h"
#include <queue>

Graph* readGraph(const char* fileName) {
	std::ifstream file(fileName);

	Graph* res = new Graph();

	int numberOfVertes = 0;
	int numberOfEdges = 0;

	file >> numberOfVertes;
	file >> numberOfEdges;

	// Add Vertices

	for (int i = 0; i < numberOfVertes; i++)
		res->addVertex(Vertex(i));

	// Add Edges

	for (int i = 0; i < numberOfEdges; i++)
	{
		int source = 0;
		int target = 0;
		int value = 0;

		file >> source;
		file >> target;
		file >> value;

		Edge toAdd = Edge(source, target);
		toAdd.setValue(value);

		res->addEdge(toAdd);
	}

	file.close();
	return res;
}

void testGraph() {

	Graph* g = readGraph("4k.txt");

	/*
	for (int i = 0; i < g->getNumberOfEdges(); i++)
	{
		Edge e = g->getEdge(i);
		std::cout << e.getSource().getValue() << " " << e.getTarget().getValue() << " " << e.getValue() << "\n";
	}
	*/

	assert(g->getNumberOfEdges() == 4000);
	assert(g->getNumberOfVerts() == 1000);

	g->removeEdge(0);
	g->removeEdge(0);
	g->removeEdge(0);

	assert(g->getOutDegree(Vertex(0)) == 4);

	g->addEdge(Edge(Vertex(0), Vertex(1)));

	assert(g->getOutDegree(Vertex(0)) == 5);

	std::cout << "ourbound edges for 0 \n";
	/*
	printEdgeArr(g->getOutboundEdges(0));

	std::cout << "inbound edges for 1 0 \n";


	printEdgeArr(g->getInboundEdges(1));

	std::cout << "end points for edge 0 \n";

	printVertexArr(g->getEdgeEndPoints(0));
	*/

	system("PAUSE");

	delete g;

}

std::queue<Vertex> queueTheAdjiacentVertices(Graph* graph,  Vertex v)
{
	std::queue<Vertex> result = std::queue<Vertex>();

	for (int i = 0; i < graph->getNumberOfVerts(); i++)
		if (graph->hasEdge(v, graph->getVertex(i)))
			result.push(graph->getVertex(i));

	return result;
}

bool search(Vertex v, std::vector<Vertex> arr) {
	for (int i = 0; i < arr.size(); i++)
		if (arr.at(i) == v)
			return true;
	return false;
}

std::vector<Vertex> BreadthFirstSearch(Graph* graph, Vertex start, Vertex end)
{
	std::vector<Vertex> result = std::vector<Vertex>(); // The list in which the path will be stored.

	std::queue<Vertex> queue = std::queue<Vertex>(); // Create empty queue.
	std::vector<Vertex> visited = std::vector<Vertex>(); // Create empty list.

	visited.push_back(start); // Mark the starting point as visited.
	queue = queueTheAdjiacentVertices(graph, start); // Add to the queue the verts that are adj to the start vertex.

	while (!queue.empty())
	{
		Vertex current = queue.front(); // Get the element from the front of the queue.
		queue.pop();	// Remove it fromm the queue.

		if (current == end)	// If the curent vertex is the end vertex the algorith is done
			return result;  // and returns the result.

		// For each node that is adj to the current one
		std::queue<Vertex> copy;
		while(! copy.empty()) {
			// Get
			Vertex n = copy.front();
			copy.pop();

			// If the vertices from the queue ar not marked
			if (search(n, visited) == false) {
				visited.push_back(n); // Mark them

				// Add to the queue the verts that are adj to n and not marked
				for (int i = 0; i < graph->getNumberOfVerts(); i++)
					if (graph->hasEdge(n, graph->getVertex(i)))
						queue.push(graph->getVertex(i));
			}
		}

	}

	return std::vector<Vertex>();
}

int main() {

	
	Graph* g = readGraph("test.txt");
	
	UI ui = UI(g);

	std::vector<Vertex> path = BreadthFirstSearch(g, Vertex(0), Vertex(4));
	for (int i = 0; i < path.size(); i++)
		std::cout << path.at(i).getValue() << " ";
	std::cout << std::endl;

	ui.start();
	

	return 0;
}