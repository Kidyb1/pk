#include <iostream>

struct Link {
    int value;
    Link* next = nullptr;
};

// Funkcja size zwracająca liczbę elementów listy
size_t size(const Link* head) {
    size_t count = 0;
    const Link* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Funkcja sum zwracająca sumę wartości przechowywanych na liście
size_t sum(const Link* head) {
    size_t total = 0;
    const Link* current = head;
    while (current != nullptr) {
        total += current->value;
        current = current->next;
    }
    return total;
}

// Funkcja pomocnicza do dodawania elementu do listy
void addToEnd(Link*& head, int value) {
    if (head == nullptr) {
        head = new Link{ value };
    }
    else {
        Link* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Link{ value };
    }
}

// Funkcja pomocnicza do wyświetlania listy
void displayList(const Link* head) {
    const Link* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Tworzenie listy
    Link* head = nullptr;
    addToEnd(head, 3);
    addToEnd(head, 5);
    addToEnd(head, 8);
    addToEnd(head, 2);

    // Wyświetlanie listy
    std::cout << "Lista: ";
    displayList(head);

    // Testowanie funkcji size i sum
    std::cout << "Liczba elementów: " << size(head) << std::endl;
    std::cout << "Suma wartości: " << sum(head) << std::endl;

    // Zwolnienie pamięci zajmowanej przez listę
    while (head != nullptr) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}