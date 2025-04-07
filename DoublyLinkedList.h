#pragma once
#include "IList.h"
#include <iostream>
#include <fstream>

class DoublyLinkedList : public IList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addAtStart(int value) override;
    void addAtEnd(int value) override;
    void addAtIndex(int index, int value) override;
    void removeAtStart() override;
    void removeAtEnd() override;
    void removeAtIndex(int index) override;
    bool search(int value) override;
    int getSize() override;
    void display() override;
    void import(std::string fileName) override;
};
