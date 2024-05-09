#include <iostream>
#include <cstdlib>


int compare(const void* a, const void* b) {
    int int_a = *static_cast<const int*>(a);
    int int_b = *static_cast<const int*>(b);


    if (int_a % 2 == 0 && int_b % 2 == 0) {
        return int_a - int_b; 
    }


    if (int_a % 2 != 0 && int_b % 2 != 0) {
        return int_b - int_a; 
    }


    if (int_a % 2 == 0) {
        return -1;
    }
    else {
        return 1;
    }
}

int main() {
    int tab[] = { 1, 4, 7, 2, 5, 9, 2, 8 };
    size_t size = sizeof(tab) / sizeof(tab[0]);


    std::qsort(tab, size, sizeof(int), compare);


    std::cout << "Posortowana tablica: ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}