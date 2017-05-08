#pragma once
class Vertex
{
private:
	int value;

public:
	Vertex(int value) : value(value) {};

	bool operator== (Vertex other) {
		if (other.getValue() == this->value)
			return true;
		return false;
	}

	int getValue() {
		return this->value;
	}

	void setValue(int value) {
		this->value = value;
	}
};

