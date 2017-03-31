#include "DynamicArray.h"


template <class T>
DynamicArray<T>::DynamicArray()
{
	this->elements = new T[DEFAULT_MAX_LENGTH];
	this->length = 0;
	this->max_length = DEFAULT_MAX_LENGTH;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->elements;
}

template <class T>
void DynamicArray<T>::add(T newElement)
{
	if (this->length+1 >= this->max_length)
		this->reallocate();

	this->elements[this->length] = newElement;
	this->length++;
}

template <class T>
bool DynamicArray<T>::remove(T element)
{
	int pos = this->find(element);
	if (pos < 0)
		return false;

	return this->remove(pos);
}

template <class T>
bool DynamicArray<T>::remove(unsigned int index)
{
	if (index >= length)
		return false;

	for (int i = index; i < length; i++)
		this->elements[i] = this->elements[i + 1];
	this->length--;

	return true;
}

template <class T>
int DynamicArray<T>::find(T element)
{
	for (int i = 0; i < length; i++)
		if (this->elements[i] == element)
			return i;

	return -1;
}

template <class T>
T DynamicArray<T>::get(unsigned int index)
{
	return this->elements[index];
}

template <class T>
int DynamicArray<T>::getLength() const
{
	return this->length;
}

template <typename T>
int DynamicArray<T>::getMaxLength() const
{
	return this->max_length;
}

template <typename T>
void DynamicArray<T>::reallocate()
{
	T *newVector = new T[this->max_length * 2];

	for (int i = 0; i < length; i++)
		newVector[i] = this->elements[i];

	delete[] elements;
	this->elements = newVector;

	this->max_length = this->max_length * 2;
}

template <typename T>
void DynamicArray<T>::insert(T e, unsigned int index)
{
	if (this->length >= this->max_length)
		this->reallocate();

	for (int i = this->length-1; i >= index; i--)
		elements[i] = elements[i - 1];
	elements[index] = e;
	length++;
}

template <typename T>
void DynamicArray<T>::set(unsigned int index, T element)
{
	this->elements[index] = element;
}
