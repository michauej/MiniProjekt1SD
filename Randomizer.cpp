#include "Randomizer.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

void generateRandomIntsToFile(string name, int count) {
    ofstream file(name);
    if (!file) {
        cout << "Błąd podczas otwierania pliku!\n";
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(INT32_MIN, INT32_MAX);

    for (int i = 0; i < count; ++i) {
        file << dist(gen) << '\n';
    }

    file.close();
}

void generate8sets(string name, int count) {
    for (int i = 0; i < 8; ++i) {
        generateRandomIntsToFile(name + "_" + to_string(count) + "_" + to_string(i) + ".txt", count);
    }
}