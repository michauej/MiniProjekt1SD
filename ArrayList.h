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

};


