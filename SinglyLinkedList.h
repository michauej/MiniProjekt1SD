#pragma once
#include "IList.h"
#include <iostream>

class SinglyLinkedList : public IList{
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~SinglyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addAtStart(int value) override {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
        size++;
    }

    void addAtEnd(int value) override {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
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
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void removeAtStart() override {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        size--;
    }

    void removeAtEnd() override {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
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
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
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