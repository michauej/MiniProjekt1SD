#pragma once
#include "IList.h"
#include <iostream>

class DoublyLinkedList : public IList{
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
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addAtStart(int value) override {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addAtEnd(int value) override {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int value) override {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtStart(value);
            return;
        }
        if (index == size) {
            addAtEnd(value);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    void removeAtStart() override {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }

    void removeAtEnd() override {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

    void removeAtIndex(int index) override {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            removeAtStart();
            return;
        }
        if (index == size - 1) {
            removeAtEnd();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    bool search(int value) override {
        Node* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    int getSize() override {
        return size;
    }

    void display() override {
        Node* current = head;
        std::cout << "[ ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "]\n";
    }
};