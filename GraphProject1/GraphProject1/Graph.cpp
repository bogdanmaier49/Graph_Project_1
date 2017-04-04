#include "Graph.h"
#include "DynamicArray.cpp"


Graph::Graph()
{
	verts = new DynamicArray<Vertex>();
	edges = new DynamicArray<Edge>();
}


Graph::~Graph()
{
	delete verts;
	delete edges;
}

void Graph::addVertex(Vertex v)
{
	this->verts->add(v);
}
void Graph::removeVertex(Vertex v)
{
	DynamicArray<int>* in = this->getInboundEdges(&v);
	DynamicArray<int>* out = this->getOutboundEdges(&v);

	for (int i = 0; i < in->getLength(); i++) {
		this->removeEdge(this->getEdge(in->get(i)).getID());
	}
	for (int i = 0; i < out->getLength(); i++) {
		this->removeEdge(this->getEdge(out->get(i)).getID());
	}

	this->verts->remove(v);
}


Vertex Graph::getVertex(unsigned int index)
{
	return this->verts->get(index);
}

bool Graph::addEdge(Edge e)
{
	for (int i = 0; i < this->edges->getLength(); i++)
		if (e.getID() == this->edges->get(i).getID())
			return false;

	this->edges->add(e);
	return true;
}
bool Graph::removeEdge(int id)
{
	for (int i=0; i<this->edges->getLength(); i++)
		if (this->edges->get(i).getID() == id) {
			this->edges->remove(i);
			return true;
		}
	return false;
}
Edge Graph::getEdge(unsigned int index)
{
	return this->edges->get(index);
}


int Graph::getNumberOfVerts() {
	return verts->getLength();
}

int Graph::hasEdge(Vertex* source, Vertex* target)
{
	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getSourceVertex()->getIndex() == source->getIndex() && e.getTargetVertex()->getIndex() == target->getIndex())
		{
			return e.getID();
		}
	}

	return -1;
}

int Graph::getInDegree(Vertex* v)
{
	int degree = 0;
	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getTargetVertex()->getIndex() == v->getIndex())
			degree++;
	}
	return degree;
}

int Graph::getOutDegree(Vertex* v)
{
	int degree = 0;
	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getSourceVertex()->getIndex() == v->getIndex())
			degree++;
	}
	return degree;
}

DynamicArray<int>* Graph::getOutboundEdges(Vertex* v)
{
	DynamicArray<int> *res = new DynamicArray<int>();

	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getSourceVertex()->getIndex() == v->getIndex())
			res->add(e.getID());
	}
	return res;
}

DynamicArray<int>* Graph::getInboundEdges(Vertex* v)
{
	DynamicArray<int> *res = new DynamicArray<int>();

	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getTargetVertex()->getIndex() == v->getIndex())
			res->add(e.getID());
	}
	return res;
}

DynamicArray<Vertex> *Graph::getEdgeEndPoints(int edgeID)
{
	DynamicArray<Vertex> *res = new DynamicArray<Vertex>();

	for (int i = 0; i < this->edges->getLength(); i++)
	{
		Edge e = this->edges->get(i);
		if (e.getID() == edgeID)
		{
			res->add(*e.getSourceVertex());
			res->add(*e.getTargetVertex());
			return res;
		}
	}

	return nullptr;
}


void Graph::setEdgeValue(unsigned int edgeIndex, int value)
{
	Edge curent = this->getEdge(edgeIndex);
	curent.setCost(value);
	this->edges->set(edgeIndex, curent);
}

int Graph::getEdgeValue(Edge e)
{
	for (int i = 0; i < this->edges->getLength(); i++)
		if (e == this->edges->get(i))
			return this->edges->get(i).getID();

	return -1;
}

int Graph::getNumberOfEdges()
{
	return edges->getLength();
}

bool Graph::hasVertex(Vertex v)
{
	for (int i = 0; i < this->verts->getLength(); i++)
		if (v.getIndex() == this->verts->get(i).getIndex())
			return true;

	return false;
}