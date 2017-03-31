#pragma once

#define DEFAULT_MAX_LENGTH 1024

template <class T>
class DynamicArray
{
private:
	T *elements;
	int length;
	int max_length;

public:
	DynamicArray();
	~DynamicArray();

	// Adds a given element.
	void add(T);

	// Removes a given element.
	// Returns true if the lement was removed,
	// false otherwise.
	bool remove(T);

	// Removes the element from a given index.
	// Returns true if the lement was removed,
	// false otherwise.
	bool remove(unsigned int index);

	// Returns the position of the element T (if exists),
	// Returns -1 if the element T does not exits.
	int find(T);


	/// NOT WORKING !!!!!!!!!!!!!!!!
	void insert(T, unsigned int index);

	void reallocate();
	void set(unsigned int index, T);

#pragma region Getters

	// Returns the element from a given index.
	T get(unsigned int index);

	int getLength() const;
	int getMaxLength() const;

#pragma endregion

};
