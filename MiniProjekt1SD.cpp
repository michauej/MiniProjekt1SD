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
        generateRandomIntsToFile(name+"_" + to_string(count)+"_"+to_string(i)+ ".txt", count);
    }
}

void test(IList& list1, IList& list2, IList& list3) {
    int x = 5000;
    string name = "Text";
    while (x < 100000) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, x); // pełny zakres int
        long long totalDurationNs1 = 0;
        long long totalDurationNs2 = 0;
        long long totalDurationNs3 = 0;
        for (int j = 0; j < 8; j++) {
            list1.import(name + "_" + to_string(x) + "_" + to_string(j) + ".txt");//wczytujemy dane z pliku, aby znów działać na tym samym zestawie
            list2.import(name + "_" + to_string(x) + "_" + to_string(j) + ".txt");//wczytujemy dane z pliku, aby znów działać na tym samym zestawie
            list3.import(name + "_" + to_string(x) + "_" + to_string(j) + ".txt");//wczytujemy dane z pliku, aby znów działać na tym samym zestawie

            for (int i = 0; i < 100; ++i) {
                int randomValue = dist(gen);
                ////////////////////////////////////////////////////
                auto start1 = chrono::high_resolution_clock::now();
                list1.removeAtIndex(randomValue); // dodajemy element do tablicy
                auto end1 = chrono::high_resolution_clock::now();
                list1.addAtIndex(randomValue, 134);
                auto duration1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
                totalDurationNs1 += duration1;
                ////////////////////////////////////////////////////
                auto start2 = chrono::high_resolution_clock::now();
                list2.removeAtIndex(randomValue); // dodajemy element do tablicy
                auto end2 = chrono::high_resolution_clock::now();
                list2.addAtIndex(randomValue, 134);
                auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
                totalDurationNs2 += duration2;
                ////////////////////////////////////////////////////
                auto start3 = chrono::high_resolution_clock::now();
                list3.removeAtIndex(randomValue); // dodajemy element do tablicy
                auto end3 = chrono::high_resolution_clock::now();
                list3.addAtIndex(randomValue, 134);
                auto duration3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
                totalDurationNs3 += duration3;
            }
        }
        double averageDuration1 = static_cast<double>(totalDurationNs1) / 800;
        double averageDuration2 = static_cast<double>(totalDurationNs2) / 800;
        double averageDuration3 = static_cast<double>(totalDurationNs3) / 800;
        cout << x << " " << averageDuration1 << " " << averageDuration2 << " " << averageDuration3 << endl;
        x += 10000;
    }
}
int main(){
	ArrayList a;
    SinglyLinkedList b;
    DoublyLinkedList c;
    test(a,b,c);
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