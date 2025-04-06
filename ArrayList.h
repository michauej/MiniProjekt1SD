#pragma once
#include "IList.h"
#incude<iostream>

template <typename T>
class ArrayList:public IList<T>
{
private:
	T* array;
	int capacity;
	int current_size;
	void resize() {
		capacity *= 2;
		T* newArray = new T[capacity];
		for (int i = 0; i < current_size; i++); {
			newArray[i] = array[i];
		}
	}
public:
	ArrayList() : capacity(10), current_size(0) {
		array = new T[capacity];
	}
	~ArrayList() {//destruktor
		delete[] array;
	}
	// Dodaje element na pocz¹tek tablicy
	void addAtStart(T value);

	// Dodaje element na koniec tablicy
	void addAtEnd(T value);

	// Dodaje element na okreœlony indeks
	void addAtIndex(int index, T value);

	// Usuwa pierwszy element
	void removeAtStart();

	// Usuwa ostatni element
	void removeAtEnd();

	// Usuwa element na okreœlonym indeksie
	void removeAtIndex(int index);

	// Wyszukuje element 
	bool search(T value);

	// Zwraca liczbê elementów
	int getSize() { return currentSize; }

	// Wyœwietla zawartoœæ tablicy (do debugowania)
	void display();

};


