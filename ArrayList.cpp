#include "ArrayList.h"

// Dodanie na pocz¹tek tablicy
template <typename T>
void ArrayList<T>::addAtStart(T value) {
    if (currentSize == capacity) resize();  // Jeœli brak miejsca, powiêksz tablicê

    // Przesuñ wszystkie elementy w prawo
    for (int i = currentSize; i > 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = value;  // Wstaw nowy element na pocz¹tek
    currentSize++;     // Zwiêksz licznik elementów
}

// Dodanie na koniec tablicy
template <typename T>
void ArrayList<T>::addAtEnd(T value) {
    if (currentSize == capacity) resize();  // Powiêksz, jeœli brak miejsca
    array[currentSize++] = value;           // Dodaj na koniec
}

// Dodanie na okreœlony indeks
template <typename T>
void ArrayList<T>::addAtIndex(int index, T value) {
    if (index < 0 || index > currentSize) {
        std::cerr << "Nieprawid³owy indeks!\n";
        return;
    }

    if (currentSize == capacity) resize();  // Powiêksz, jeœli trzeba

    // Przesuñ elementy w prawo od podanego indeksu
    for (int i = currentSize; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = value;  // Wstaw nowy element
    currentSize++;
}

// Usuniêcie pierwszego elementu
template <typename T>
void ArrayList<T>::removeAtStart() {
    if (currentSize == 0) {
        std::cerr << "Tablica jest pusta!\n";
        return;
    }

    // Przesuñ wszystkie elementy w lewo
    for (int i = 0; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }

    currentSize--;  // Zmniejsz licznik
}

// Usuniêcie ostatniego elementu
template <typename T>
void ArrayList<T>::removeAtEnd() {
    if (currentSize == 0) {
        std::cerr << "Tablica jest pusta!\n";
        return;
    }
    currentSize--;  // Wystarczy zmniejszyæ licznik
}

// Usuniêcie elementu na indeksie
template <typename T>
void ArrayList<T>::removeAtIndex(int index) {
    if (index < 0 || index >= currentSize) {
        std::cerr << "Nieprawid³owy indeks!\n";
        return;
    }

    // Przesuñ elementy w lewo od indeksu
    for (int i = index; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }

    currentSize--;
}

// Wyszukiwanie elementu
template <typename T>
bool ArrayList<T>::search(T value) {
    for (int i = 0; i < currentSize; i++) {
        if (array[i] == value) return true;
    }
    return false;
}

// Wyœwietlanie tablicy (do testów)
template <typename T>
void ArrayList<T>::display() {
    std::cout << "[ ";
    for (int i = 0; i < currentSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

//instancjonowanie szablonu (aby unikn¹æ b³êdów linkera)
template class ArrayList<int>;