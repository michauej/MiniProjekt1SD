#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::Node::Node(int val) : data(val), next(nullptr) {}

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void SinglyLinkedList::addAtStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (!tail) tail = head;
    size++;
}

void SinglyLinkedList::addAtEnd(int value) {
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

void SinglyLinkedList::addAtIndex(int index, int value) {
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

void SinglyLinkedList::removeAtStart() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) tail = nullptr;
    size--;
}

void SinglyLinkedList::removeAtEnd() {
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

void SinglyLinkedList::removeAtIndex(int index) {
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

bool SinglyLinkedList::search(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int SinglyLinkedList::getSize() {
    return size;
}

void SinglyLinkedList::display() {
    Node* current = head;
    cout << "[ ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]\n";
}

void SinglyLinkedList::import(string fileName) {
    // Usunięcie istniejącej listy
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;

    ifstream file(fileName);
    if (!file) {
        cerr << "Nie można otworzyć pliku: " << fileName << "\n";
        return;
    }

    int value;
    while (file >> value) {
        addAtEnd(value);
    }

    file.close();
}
