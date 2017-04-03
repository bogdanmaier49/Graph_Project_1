#include "UI.h"



UI::UI(Graph* graph)
{
	this->graph = graph;
}


UI::~UI()
{
	delete graph;
}

void UI::printGraph()
{
	for (int i = 0; i < graph->getNumberOfEdges(); i++)
	{
		Edge e = graph->getEdge(i);
		std::cout << e.getSourceVertex()->getIndex() << " " << e.getTargetVertex()->getIndex() << " " << e.getCost() << "\n";
	}
}

void UI::printNumberOfVertices()
{
	std::cout << "Number of vertices: " << graph->getNumberOfVerts();
}

void UI::printNumberOfEdges()
{
	std::cout << "Number of edges: " << graph->getNumberOfEdges();
}

void UI::printHasEdge()
{

	Vertex v1 = this->readVertex("Source Vertex: ");
	Vertex v2 = this->readVertex("Target Vertex: ");

	int res = graph->hasEdge(&v1, &v2);
	if (res != -1)
		std::cout << "The graph has edge from " << v1.getIndex() << " to " << v2.getIndex() << " with ID: " << res;
	else 
		std::cout << "The graph has no edge from " << v1.getIndex() << " to " << v2.getIndex();
}

void UI::printInDegree()
{
	Vertex v = this->readVertex("In degree for vertex: ");
	std::cout << "In degree for vertex " << v.getIndex() << " is: " << graph->getInDegree(&v);
}

void UI::printOutDegree()
{
	Vertex v = this->readVertex("Out degree for vertex: ");
	std::cout << "Out degree for vertex " << v.getIndex() << " is: " << graph->getOutDegree(&v);
}

void UI::printEdgeEndPoints()
{

	int edge = this->readInt("End points for edge with ID: ");

	if (edge < 0)
		return;

	DynamicArray<Vertex>* res = graph->getEdgeEndPoints(edge);
	if (res->getLength() > 0) {
		std::cout << "Edge points for edge id " << edge << ": ";
		this->printVertexArray(res);
	}
	else
		std::cout << "The edge with id " << edge << " has no end points";
	delete res;
}

void UI::printVertexArray(DynamicArray<Vertex>* arr)
{
	for (int i = 0; i < arr->getLength(); i++)
		std::cout << arr->get(i).getIndex() << " ";
}

int UI::readInt(const char* msg)
{
	std::cout << msg;
	int res = 0;
	std::cin >> res;
	return res;
}

void UI::cls()
{
	system("@cls||clear");
}

Vertex UI::readVertex(const char* msg)
{
	std::cout << msg;
	int index = 0;
	std::cin >> index;
	Vertex res = Vertex(index);
	return res;
}

void UI::start()
{
	while (true) {
		this->cls();

		std::cout << " 1 - print graph\n";
		std::cout << " 2 - print number of vertices\n";
		std::cout << " 3 - print number of edges\n";
		std::cout << " 4 - print if exits edge\n";
		std::cout << " 5 - print in degree\n";
		std::cout << " 6 - print out degree\n";
		std::cout << " 7 - print edge end points\n";
		std::cout << " 0 - Exit\n";

		int command = this->readInt("Command: ");

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