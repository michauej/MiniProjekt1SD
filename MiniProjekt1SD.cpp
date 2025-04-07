#include <iostream>
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
	ArrayList a;
	//SinglyLinkedList a;
	//DoublyLinkedList a;
	a.addAtEnd(5);
	a.addAtStart(1);
	a.addAtIndex(1, 3);
	a.display();
	a.removeAtStart();
	a.display();
	a.removeAtIndex(1);
	a.display();
}