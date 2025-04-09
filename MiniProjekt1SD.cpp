#include <iostream>
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Test.h"
#include <string>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

int menu(IList& list) {
    int option;
    do {
        cout << "1. Dodaj na początek\n";
        cout << "2. Dodaj na koniec\n";
        cout << "3. Dodaj na indeksie\n";
        cout << "4. Usuń z początku\n";
        cout << "5. Usuń z końca\n";
        cout << "6. Usuń z indeksu\n";
        cout << "7. Szukaj wartości\n";
        cout << "8. Wyświetl rozmiar\n";
        cout << "9. Wyświetl zawartość\n";
        cout << "10. Importuj z pliku\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> option;

        int value, index;
        string fileName;

        switch (option) {
        case 1:
            cout << "Podaj wartość: ";
            cin >> value;
            list.addAtStart(value);
            break;
        case 2:
            cout << "Podaj wartość: ";
            cin >> value;
            list.addAtEnd(value);
            break;
        case 3:
            cout << "Podaj indeks i wartość: ";
            cin >> index >> value;
            list.addAtIndex(index, value);
            break;
        case 4:
            list.removeAtStart();
            break;
        case 5:
            list.removeAtEnd();
            break;
        case 6:
            cout << "Podaj indeks: ";
            cin >> index;
            list.removeAtIndex(index);
            break;
        case 7:
            cout << "Podaj wartość: ";
            cin >> value;
            cout << (list.search(value) ? "Znaleziono\n" : "Nie znaleziono\n");
            break;
        case 8:
            cout << "Rozmiar listy: " << list.getSize() << endl;
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Podaj nazwę pliku: ";
            cin >> fileName;
            list.import(fileName);
            break;
        case 0:
            cout << "Zakończono.\n";
            break;
        default:
            cout << "Nieznana opcja!\n";
            break;
        }
    } while (option != 0);
    return 0;
}
int main(){
	ArrayList a;
    SinglyLinkedList b;
    DoublyLinkedList c;

    //MENU
    cout << "--- Wybierz strukturę danych ---\n";
    cout << "1. ArrayList\n";
    cout << "2. SinglyLinkedList\n";
    cout << "3. DoublyLinkedList\n";
    cout << "Twój wybór: ";

    int choice;
    cin >> choice;
    switch (choice) {
    case 1: menu(a); break;
    case 2: menu(b); break;
    case 3: menu(c); break;
    default:
        cout << "Nieprawidłowy wybór. Kończę program.\n";
        return 1;
    }
//test(a,b,c);
//SinglyLinkedList a;
//DoublyLinkedList a;
/*
a.addAtEnd(5);
a.addAtStart(1);
a.addAtIndex(1, 3);
a.display();
a.removeAtStart();
a.display();
a.removeAtIndex(1);
a.display();
*/

}