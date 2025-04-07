#include <iostream>
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <string>
#include <fstream>
#include <random>
#include <chrono>
using namespace std;

void generateRandomIntsToFile(string name,int count) {
    ofstream file(name);
    if (!file) {
        cout << "Błąd podczas otwierania pliku!\n";
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(INT32_MIN, INT32_MAX); // pełny zakres int

    for (int i = 0; i < count; ++i) {
        int randomValue = dist(gen);
        file << randomValue << '\n';
    }

    file.close();
}

void generate8sets(string name, int count) {
    for (int i = 0; i < 8; i++) {
        generateRandomIntsToFile(name+to_string(i)+".txt", 5000);
    }
}

void test(IList& list) {
    int x = 5000;
    generateRandomIntsToFile("Text.txt",x );
    while (x < 100000) {
        long long totalDurationNs = 0;
        for (int i = 0; i < 1000; ++i) {
            list.import("Text.txt");//wczytujemy dane z pliku, aby znów działać na tym samym zestawie
            auto start = chrono::high_resolution_clock::now();
            list.addAtEnd(2); // dodajemy element do tablicy
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            totalDurationNs += duration;
        }

        double averageDuration = static_cast<double>(totalDurationNs) / 1000;
        cout << x << " " << averageDuration << endl;
        x += 10000;
    }
}
int main(){
	ArrayList a;
    generate8sets("dane", 50);
	//test(a);
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