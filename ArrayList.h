#pragma once
#include "IList.h"
#include <iostream>

template <typename T>
class ArrayList : public IList<T> {
private:
    T* array;
    int capacity;
    int currentSize;

    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    ArrayList() : capacity(10), currentSize(0) {
        array = new T[capacity];
    }

    ~ArrayList() {
        delete[] array;
    }

    void addAtStart(T value) override {
        if (currentSize == capacity) resize();
        for (int i = currentSize; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = value;
        currentSize++;
    }

    void addAtEnd(T value) override {
        if (currentSize == capacity) resize();
        array[currentSize++] = value;
    }

    void addAtIndex(int index, T value) override {
        if (index < 0 || index > currentSize) {
            std::cerr << "Invalid index!\n";
            return;
        }
        if (currentSize == capacity) resize();
        for (int i = currentSize; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = value;
        currentSize++;
    }

    void removeAtStart() override {
        if (currentSize == 0) return;
        for (int i = 0; i < currentSize - 1; i++) {
            array[i] = array[i + 1];
        }
        currentSize--;
    }

    void removeAtEnd() override {
        if (currentSize > 0) currentSize--;
    }

    void removeAtIndex(int index) override {
        if (index < 0 || index >= currentSize) return;
        for (int i = index; i < currentSize - 1; i++) {
            array[i] = array[i + 1];
        }
        currentSize--;
    }

    bool search(T value) override {
        for (int i = 0; i < currentSize; i++) {
            if (array[i] == value) return true;
        }
        return false;
    }

    int getSize() override {
        return currentSize;
    }

    void display() override {
        std::cout << "[ ";
        for (int i = 0; i < currentSize; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "]\n";
    }
};