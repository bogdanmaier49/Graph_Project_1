#pragma once
class Vertex
{

	int index;

public:
	Vertex(int);
	Vertex() {}
	bool operator==(Vertex);
	inline int getIndex() const { return index; };
};

