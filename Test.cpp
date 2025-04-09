#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Test.h"
#include "Randomizer.h"

using namespace std;
    void test(IList& list1, IList& list2, IList& list3) {
        int x = 5000;
        string name = "Text";
        
        while (x < 100000) {
            //generate8sets(name, x); // odkomentować przy 1 iteracji
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(0, x);

            long long totalDurationNs1 = 0;
            long long totalDurationNs2 = 0;
            long long totalDurationNs3 = 0;

            for (int j = 0; j < 8; j++) {
                string file = name + "_" + to_string(x) + "_" + to_string(j) + ".txt";

                list1.import(file);
                list2.import(file);
                list3.import(file);

                for (int i = 0; i < 100; ++i) {
                    int randomValue = dist(gen);
                    //test 1 struktury
                    auto start1 = chrono::high_resolution_clock::now();
                    list1.addAtIndex(randomValue, 134);
                    auto end1 = chrono::high_resolution_clock::now();
                    list1.removeAtIndex(randomValue);
                    totalDurationNs1 += chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
                    //test 2 struktury
                    auto start2 = chrono::high_resolution_clock::now();
                    list2.addAtIndex(randomValue, 134);
                    auto end2 = chrono::high_resolution_clock::now();
                    list2.removeAtIndex(randomValue);
                    totalDurationNs2 += chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
                    //test 3 struktury
                    auto start3 = chrono::high_resolution_clock::now();
                    list3.addAtIndex(randomValue, 134);
                    auto end3 = chrono::high_resolution_clock::now();
                    list3.removeAtIndex(randomValue);
                    totalDurationNs3 += chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
                }
            }
            //licznie średniej dla każdej struktury
            double avg1 = static_cast<double>(totalDurationNs1) / 800;
            double avg2 = static_cast<double>(totalDurationNs2) / 800;
            double avg3 = static_cast<double>(totalDurationNs3) / 800;

            cout << x << " " << avg1 << " " << avg2 << " " << avg3 << endl;

            x += 10000;
        }
    }