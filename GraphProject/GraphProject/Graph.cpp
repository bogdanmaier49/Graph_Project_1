#include "Graph.h"



Graph::Graph()
{
	this->vertices = new std::vector<Vertex>();
	this->edges = new std::vector<Edge>();
}


Graph::~Graph()
{
	delete this->vertices;
	delete this->edges;
}

void Graph::addVertex(Vertex v)
{
	this->vertices->push_back(v);
}

void Graph::removeVertex(Vertex v)
{
	this->vertices->erase(this->vertices->begin() + this->getVertexIndex(v));

	for (int i = 0; i < edges->size(); i++)
		if (this->getEdge(i).getSource() == v || this->getEdge(i).getTarget() == v)
			this->edges->erase(this->edges->begin() + i);
}

Vertex Graph::getVertex(unsigned int index)
{
	return this->vertices->at(index);
}

void Graph::addEdge(Edge e)
{
	this->edges->push_back(e);
}

void Graph::removeEdge(int id)
{
	this->edges->erase(this->edges->begin() + id);
}

Edge Graph::getEdge(unsigned int index)
{
	return this->edges->at(index);
}

int Graph::getNumberOfVerts()
{
	return this->vertices->size();
}

int Graph::getNumberOfEdges()
{
	return this->edges->size();
}

bool Graph::hasEdge(Vertex soruce, Vertex target)
{
	for (int i = 0; i < this->edges->size(); i++)
		if (this->edges->at(i).getSource() == soruce && this->edges->at(i).getTarget() == target)
			return true;
	return false;
}

int Graph::getInDegree(Vertex vertex)
{
	int result = 0;
	for (int i = 0; i < this->edges->size(); i++)
		if (this->edges->at(i).getTarget() == vertex)
			result++;
	return result;
}

int Graph::getOutDegree(Vertex vertex)
{
	int result = 0;
	for (int i = 0; i < this->edges->size(); i++)
		if (this->edges->at(i).getSource() == vertex)
			result++;
	return result;
}

std::vector<Edge>* Graph::getOutboundEdges(Vertex v)
{
	std::vector<Edge>* res = new std::vector<Edge>();

	for (int i = 0; i < this->edges->size(); i++)
	{
		Edge e = this->edges->at(i);
		if (e.getSource() == v)
			res->push_back(e);
	}
	return res;
}

std::vector<Edge>* Graph::getInboundEdges(Vertex v)
{
	std::vector<Edge>* res = new std::vector<Edge>();

	for (int i = 0; i < this->edges->size(); i++)
	{
		Edge e = this->edges->at(i);
		if (e.getTarget() == v)
			res->push_back(e);
	}
	return res;
}

std::vector<Vertex>* Graph::getEdgeEndPoints(int EdgeID)
{
	std::vector<Vertex> *res = new std::vector<Vertex>();

	for (int i = 0; i < this->edges->size(); i++)
	{
		if (i == EdgeID)
		{
			Edge e = this->edges->at(i);
			res->push_back(e.getSource());
			res->push_back(e.getTarget());
			return res;
		}
	}

	return nullptr;
}



int Graph::getVertexIndex(Vertex v)
{
	for (int i = 0; i < vertices->size(); i++)
		if (this->vertices->at(i) == v)
			return i;
	return -1;
}

bool Graph::hasVertex(Vertex v)
{
	for (int i = 0; i < this->vertices->size(); i++)
		if (v== this->vertices->at(i))
			return true;

	return false;
}

void Graph::setEdgeValue(unsigned int index, int value)
{
	Edge curent = this->getEdge(index);
	curent.setValue(value);
	this->edges->at(index) = curent;
}

int Graph::getEdgeValue(Edge e)
{
	return e.getValue();
}
