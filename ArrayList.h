#pragma once
#include "IList.h"
#include <iostream>

using namespace std;

class ArrayList : public IList{
private:
    int* array;
    int capacity;
    int currentSize;

    void resize() {
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    ArrayList(int cap=10);
    ~ArrayList();
    void addAtStart(int value) override;
    void addAtEnd(int value) override;
    void addAtIndex(int index, int value) override;
    void removeAtStart() override;
    void removeAtEnd() override;
    void removeAtIndex(int index) override;
    bool search(int value) override;
    int getSize() override;
    void display() override;
    void import(string fileName) override;
};