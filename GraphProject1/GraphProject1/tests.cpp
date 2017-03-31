#include "Tests.h"
#include "DynamicArray.cpp"

void TestDynamicArray()
{
	DynamicArray<std::string> *arr = new DynamicArray<std::string>();

	assert(arr->getLength() == 0);
	assert(arr->getMaxLength() == DEFAULT_MAX_LENGTH);
	
	// TEST the add(T) function

	arr->add("unu");
	arr->add("doi");
	arr->add("trei");
	arr->add("patru");
	
	assert(arr->get(0) == "unu");
	assert(arr->get(1) == "doi");
	assert(arr->get(2) == "trei");
	assert(arr->get(3) == "patru");
	


	// TEST the remove(T) / remove(int) functions

	arr->remove("unu");

	assert(arr->getLength() == 3);
	assert(arr->get(0) == "doi");
	assert(arr->get(1) == "trei");
	assert(arr->get(2) == "patru");

	arr->remove(1);

	assert(arr->getLength() == 2);
	assert(arr->get(0) == "doi");
	assert(arr->get(1) == "patru");

	// TEST the find(T) function

	assert(arr->find("doi") == 0);
	assert(arr->find("patru") == 1);
	assert(arr->find("cinci") == -1);

	// TEST the insert(T, int) function
	

	delete arr;
}

void TestGraph()
{
	Graph *g = new Graph();

	assert(g->getNumberOfVerts() == 0);
	assert(g->getNumberOfEdges() == 0);

	Vertex v0 = { 0 };
	Vertex v1 = { 1 };
	Vertex v2 = { 2 };
	Vertex v3 = { 3 };
	Vertex v4 = { 4 };

	g->addVertex(v0);
	g->addVertex(v1);
	g->addVertex(v2);
	g->addVertex(v3);
	g->addVertex(v4);

	assert(g->getNumberOfVerts() == 5);

	g->addEdge(Edge(0, &v0, &v0));
	g->addEdge(Edge(1, &v0, &v1));
	g->addEdge(Edge(2, &v1, &v2));
	g->addEdge(Edge(3, &v2, &v1));
	g->addEdge(Edge(4, &v2, &v3));
	g->addEdge(Edge(5, &v1, &v3));

	assert(g->getOutDegree(&v0) == 2);
	assert(g->getOutDegree(&v1) == 2);
	assert(g->getOutDegree(&v2) == 2);
	assert(g->getOutDegree(&v3) == 0);
	assert(g->getOutDegree(&v4) == 0);

	assert(g->getInDegree(&v0) == 1);
	assert(g->getInDegree(&v1) == 2);
	assert(g->getInDegree(&v2) == 1);
	assert(g->getInDegree(&v3) == 2);
	assert(g->getInDegree(&v4) == 0);

	DynamicArray<int> *outboundEdges = g->getOutboundEdges(&v1);
	for (int i = 0; i < outboundEdges->getLength(); i++)
		std::cout << outboundEdges->get(i) << " ";

	DynamicArray<int> *inboundEdges = g->getInboundEdges(&v1);
	for (int i = 0; i < inboundEdges->getLength(); i++)
		std::cout << inboundEdges->get(i) << " ";
	std::cout << std::endl;

	DynamicArray<Vertex> *endPoints1 = g->getEdgeEndPoints(1);
	std::cout << "End points edge(v0-v1): ";
	for (int i = 0; i < endPoints1->getLength(); i++)
		std::cout << endPoints1->get(i).getIndex() << " ";
	std::cout << std::endl;

	g->setEdgeValue(0, 100);
	assert(g->getEdge(0).getCost() == 100);

	delete g;
}