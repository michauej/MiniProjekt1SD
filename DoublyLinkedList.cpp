#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::addAtStart(int value) {
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

void DoublyLinkedList::addAtEnd(int value) {
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

void DoublyLinkedList::addAtIndex(int index, int value) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addAtStart(value);
        return;
    }
    if (index == size) {
        addAtEnd(value);
        return;
    }

    Node* current;
    // Jeśli index jest bliżej początku to zaczynamy od początku, jeżeli nie to od tyłu
    if (index <= size / 2) {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
    else {
        current = tail;
        for (int i = size - 1; i > index - 1; i--) {
            current = current->prev;
        }
    }

    Node* newNode = new Node(value);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}


void DoublyLinkedList::removeAtStart() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    size--;
}

void DoublyLinkedList::removeAtEnd() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    size--;
}

void DoublyLinkedList::removeAtIndex(int index) {
    if (index < 0 || index >= size) return;

    if (index == 0) {
        removeAtStart();
        return;
    }

    if (index == size - 1) {
        removeAtEnd();
        return;
    }

    Node* current;
    // Jeśli index jest bliżej początku to zaczynamy od początku, jeżeli nie to od tyłu 
    if (index <= size / 2) {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
    else {
        current = tail;
        for (int i = size - 1; i > index; i--) {
            current = current->prev;
        }
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}


bool DoublyLinkedList::search(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

int DoublyLinkedList::getSize() {
    return size;
}

void DoublyLinkedList::display() {
    Node* current = head;
    std::cout << "[ ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "]\n";
}

void DoublyLinkedList::import(std::string fileName) {
    // Cleaning up existing list
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;

    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Cannot open file: " << fileName << "\n";
        return;
    }

    int value;
    while (file >> value) {
        addAtEnd(value);
    }

    file.close();
}
