#include "ArrayList.h"

// Dodanie na pocz�tek tablicy
template <typename T>
void ArrayList<T>::addAtStart(T value) {
    if (currentSize == capacity) resize();  // Je�li brak miejsca, powi�ksz tablic�

    // Przesu� wszystkie elementy w prawo
    for (int i = currentSize; i > 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = value;  // Wstaw nowy element na pocz�tek
    currentSize++;     // Zwi�ksz licznik element�w
}

// Dodanie na koniec tablicy
template <typename T>
void ArrayList<T>::addAtEnd(T value) {
    if (currentSize == capacity) resize();  // Powi�ksz, je�li brak miejsca
    array[currentSize++] = value;           // Dodaj na koniec
}

// Dodanie na okre�lony indeks
template <typename T>
void ArrayList<T>::addAtIndex(int index, T value) {
    if (index < 0 || index > currentSize) {
        std::cerr << "Nieprawid�owy indeks!\n";
        return;
    }

    if (currentSize == capacity) resize();  // Powi�ksz, je�li trzeba

    // Przesu� elementy w prawo od podanego indeksu
    for (int i = currentSize; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = value;  // Wstaw nowy element
    currentSize++;
}

// Usuni�cie pierwszego elementu
template <typename T>
void ArrayList<T>::removeAtStart() {
    if (currentSize == 0) {
        std::cerr << "Tablica jest pusta!\n";
        return;
    }

    // Przesu� wszystkie elementy w lewo
    for (int i = 0; i < currentSize - 1; i++) {
        array[i] = array[i + 1];
    }

    currentSize--;  // Zmniejsz licznik
}

// Usuni�cie ostatniego elementu
template <typename T>
void ArrayList<T>::removeAtEnd() {
    if (currentSize == 0) {
        std::cerr << "Tablica jest pusta!\n";
        return;
    }
    currentSize--;  // Wystarczy zmniejszy� licznik
}

// Usuni�cie elementu na indeksie
template <typename T>
void ArrayList<T>::removeAtIndex(int index) {
    if (index < 0 || index >= currentSize) {
        std::cerr << "Nieprawid�owy indeks!\n";
        return;
    }

    // Przesu� elementy w lewo od indeksu
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

// Wy�wietlanie tablicy (do test�w)
template <typename T>
void ArrayList<T>::display() {
    std::cout << "[ ";
    for (int i = 0; i < currentSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

//instancjonowanie szablonu (aby unikn�� b��d�w linkera)
template class ArrayList<int>;