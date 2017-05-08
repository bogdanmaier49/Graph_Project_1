#include "UI.h"



Vertex UI::readVertex(const char * msg)
{
	int val = 0;
	std::cout << msg;
	std::cout << "Value: ";
	std::cin >> val;
	return Vertex(val);
}

Edge UI::readEdge(const char * msg)
{
	std::cout << msg << std::endl;
	Vertex source = this->readVertex("Soruce Vertex: \n");
	Vertex target = this->readVertex("Target Vertex: \n");

	return Edge(source, target);
}

void UI::printGraph()
{
	for (int i = 0; i < graph->getNumberOfEdges(); i++)
	{
		Edge e = graph->getEdge(i);
		std::cout << e.getSource().getValue() << " " << e.getTarget().getValue() << " " << e.getValue() << "\n";
	}
}

void UI::printNumberOfVertices()
{
	std::cout << "Number Of Vertices: " << this->graph->getNumberOfVerts() << std::endl;
}

void UI::printNumberOfEdges()
{
	std::cout << "Number Of Edges: " << this->graph->getNumberOfEdges() << std::endl;
}

void UI::printHasEdge()
{
	Vertex v1 = this->readVertex("Source Vertex: ");
	Vertex v2 = this->readVertex("Target Vertex: ");

	int res = graph->hasEdge(v1, v2);
	if (res != -1)
		std::cout << "The graph has edge from " << v1.getValue() << " to " << v2.getValue() << " with ID: " << res;
	else
		std::cout << "The graph has no edge from " << v1.getValue() << " to " << v2.getValue();
}

void UI::printInDegree()
{
	Vertex v = this->readVertex("In degree for vertex: ");
	std::cout << "In degree for vertex " << v.getValue() << " is: " << graph->getInDegree(v);
}

void UI::printOutDegree()
{
	Vertex v = this->readVertex("Out degree for vertex: ");
	std::cout << "Out degree for vertex " << v.getValue() << " is: " << graph->getOutDegree(v);
}

void UI::printEdgeEndPoints()
{
	int edge = 0;
	std::cout << "End points for edge with ID: ";
	std::cin >> edge;

	if (edge < 0)
		return;

	std::vector<Vertex>* res = graph->getEdgeEndPoints(edge);
	if (res->size() > 0) {
		std::cout << "Edge points for edge id " << edge << ": ";
		this->printVertexArray(res);
	}
	else
		std::cout << "The edge with id " << edge << " has no end points";
	delete res;
}

void UI::printVertexArray(std::vector<Vertex>* arr)
{
	for (int i = 0; i < arr->size(); i++)
		std::cout << arr->at(i).getValue() << " ";
}

void UI::printOutboundEdges()
{
	Vertex v = readVertex("Outbound edges for vertex: ");

	// check if the vertex exits
	if (this->graph->hasVertex(v) == false)
	{
		std::cout << "The given vertex " << v.getValue() << " does not exits.\n";
		return;
	}

	std::vector<Edge> *out = this->graph->getOutboundEdges(v);

	printEdgeArr(out);
	
	delete out;
}

void UI::printInboundEdges()
{
	Vertex v = readVertex("Inbound edges for vertex: ");

	// check if the vertex exits
	if (this->graph->hasVertex(v) == false)
	{
		std::cout << "The given vertex " << v.getValue() << " does not exits.\n";
		return;
	}

	std::vector<Edge> *in = this->graph->getInboundEdges(v);

	printEdgeArr(in);

	delete in;
}

void UI::addVertex()
{
	int vertexIndex = 0;
	std::cout << "Vertex ID: ";
	std::cin >> vertexIndex;

	for (int i = 0; i < this->graph->getVertexArray()->size(); i++)
		if (this->graph->getVertex(i).getValue() == vertexIndex) {
			std::cout << "The vertex " << vertexIndex << " alleary exits.\n";
			return;
		}

	this->graph->addVertex(Vertex(vertexIndex));
	std::cout << "The vertex was added successfuly.\n";
}

void UI::removeVertex()
{
	int vertexIndex = 0;
	std::cout << "Vertex ID: ";
	std::cin >> vertexIndex;
	
	for (int i = 0; i < this->graph->getVertexArray()->size(); i++)
		if (this->graph->getVertex(i).getValue() == vertexIndex) {
			this->graph->removeVertex(this->graph->getVertex(vertexIndex));
			std::cout << "The vertex was removed successfuly.\n";
			return;
		}


	std::cout << "The vertex " << vertexIndex << " does not exits.\n";
}

void UI::addEdge()
{
	Edge e = this->readEdge("Add edge to the graph: \n");

	if (graph->edgeExists(e))
	{
		std::cout << "The edge already exits! \n";
		return;
	} 

	std::cout << "Edge added! \n";
	this->graph->addEdge(e);
}

void UI::removeEdge()
{
	int id = 0;
	std::cout << "Edge id: ";
	std::cin >> id;

	if (id >= 0 && id < this->graph->getNumberOfEdges()) {
		this->graph->removeEdge(id);
		std::cout << "The edge was removd.\n";
	}
	else
		std::cout << "The edge could not be removed.\n";
}

void UI::changeEdgeData()
{

}

void UI::start()
{
	while (true) {
		this->cls();

		std::cout << " 1  - print graph\n";
		std::cout << " 2  - print number of vertices\n";
		std::cout << " 3  - print number of edges\n";
		std::cout << " 4  - print if exits edge\n";
		std::cout << " 5  - print in degree\n";
		std::cout << " 6  - print out degree\n";
		std::cout << " 7  - print edge end points\n";
		std::cout << " 8  - add vertex\n";
		std::cout << " 9  - remove vertex\n";
		std::cout << " 10 - add edge\n";
		std::cout << " 11 - remove edge\n";
		std::cout << " 12 - change edge value\n";
		std::cout << " 13 - print outbound edges of a vertex\n";
		std::cout << " 14 - print inbound edges of a vertex\n";
		std::cout << " 0 - Exit\n";

		int command = 0;
		std::cout << "Command: ";
		std::cin >> command;

		switch (command)
		{
		case 1:
			this->printGraph();
			std::cout << std::endl;
			system("PAUSE");
			break;
		case 2:
			this->printNumberOfVertices();
			std::cout << std::endl;
			system("PAUSE");
			break;
		case 3:
			this->printNumberOfEdges();
			std::cout << std::endl;
			system("PAUSE");
			break;
		case 4:
			this->printHasEdge();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 5:
			this->printInDegree();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 6:

			this->printOutDegree();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 7:
			this->printEdgeEndPoints();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 8:
			this->addVertex();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 9:
			this->removeVertex();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 10:
			this->addEdge();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 11:
			this->removeEdge();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 12:
			this->changeEdgeData();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 13:
			this->printOutboundEdges();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 14:
			this->printInboundEdges();

			std::cout << std::endl;
			system("PAUSE");

			break;
		case 0:
			return;
			break;
		default:
			std::cout << "Unknown command!\n";

			std::cout << std::endl;
			system("PAUSE");

			break;
		}

	}
}
