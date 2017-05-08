#pragma once

#include "Vertex.h"
#include "Edge.h"
#include <vector>

class Graph
{
	std::vector<Vertex>* vertices;
	std::vector<Edge>* edges;

public:
	Graph();
	~Graph();

	void addVertex(Vertex v);
	void removeVertex(Vertex v);
	Vertex getVertex(unsigned int index);

	void addEdge(Edge e);
	void removeEdge(int index);
	Edge getEdge(unsigned int index);

	int getNumberOfVerts();
	int getNumberOfEdges();
	bool hasEdge(Vertex, Vertex);
	int getInDegree(Vertex);
	int getOutDegree(Vertex);
	std::vector<Edge>* getOutboundEdges(Vertex);
	std::vector<Edge>* getInboundEdges(Vertex);
	std::vector<Vertex> *getEdgeEndPoints(int EdgeID);

	int getVertexIndex(Vertex v);

	bool hasVertex(Vertex v);

	std::vector<Vertex>* getVertexArray() const { return this->vertices; }
	std::vector<Edge>* getEdgeArray() const { return this->edges; }

	void setEdgeValue(unsigned int, int);
	int getEdgeValue(Edge);

	bool edgeExists(Edge e) {

		for (int i = 0; i < this->edges->size(); i++)
			if (this->edges->at(i) == e)
				return true;

		return false;
	}

};

