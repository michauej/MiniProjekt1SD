#include "ArrayList.h"
#include <iostream>
#include <fstream>

ArrayList::ArrayList(int cap) : currentSize(0), capacity(cap) {
    array = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] array;
}

 
void ArrayList::addAtStart(int value){
    if (currentSize == capacity) resize();
    for (int i = currentSize; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    currentSize++;
}
 
void ArrayList::addAtEnd(int value){
    if (currentSize == capacity) resize();
    array[currentSize++] = value;
}

 
void ArrayList::addAtIndex(int index, int value){
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
 
void ArrayList::removeAtStart(){
    if (currentSize == 0) return;
    for (int i = 0; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }
    currentSize--;
}

 
void ArrayList::removeAtEnd(){
    if (currentSize > 0) currentSize--;
}

 
void ArrayList::removeAtIndex(int index){
    if (index < 0 || index >= currentSize) return;
    for (int i = index; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }
    currentSize--;
}
 
bool ArrayList::search( int value){
    for (int i = 0; i < currentSize; i++) {
        if (array[i] == value) return true;
    }
    return false;
}
 
int ArrayList::getSize(){
    return currentSize;
}
 
void ArrayList::display(){
    std::cout << "[ ";
    for (int i = 0; i < currentSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

void ArrayList::import(string fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Nie można otworzyć pliku: " << fileName << "\n";
        return;
    }

    int value;
    currentSize = 0; // resetujemy dane

    while (file >> value) {
        addAtEnd(value);
    }

    file.close();
    //std::cout << "Import z pliku zakończony.\n";
}