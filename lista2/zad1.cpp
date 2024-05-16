#include <iostream>


int suma(const int tab[], unsigned size) {
    int sum = 0;
    for (unsigned i = 0; i < size; ++i) {
        sum += tab[i];
    }
    return sum;
}


void test_suma() {
    int tab[] = { 1, 2, 3, 4, 5 };
    unsigned size = sizeof(tab) / sizeof(tab[0]);
    int expected_sum = 15;
    int result = suma(tab, size);
    std::cout << "Suma: " << result << std::endl;
    if (result == expected_sum) {
        std::cout << "Test dla funkcji suma: PASS" << std::endl;
    }
    else {
        std::cout << "Test dla funkcji suma: FAIL" << std::endl;
    }
}


void suma(const int tab[], unsigned size, int* result) {
    *result = suma(tab, size);
}


void test_suma_result() {
    int tab[] = { 1, 2, 3, 4, 5 };
    unsigned size = sizeof(tab) / sizeof(tab[0]);
    int expected_sum = 15;
    int result;
    suma(tab, size, &result);
    std::cout << "Suma (z przekazaniem przez wskaźnik): " << result << std::endl;
    if (result == expected_sum) {
        std::cout << "Test dla funkcji suma (z przekazaniem przez wskaźnik): PASS" << std::endl;
    }
    else {
        std::cout << "Test dla funkcji suma (z przekazaniem przez wskaźnik): FAIL" << std::endl;
    }
}

void pisz(const int* tab, size_t size, std::ostream& out = std::cout) {
    for (size_t i = 0; i < size; ++i) {
        out << tab[i] << " ";
    }
    out << std::endl;
}


void test_pisz() {
    int tab[] = { 1, 2, 3, 4, 5 };
    unsigned size = sizeof(tab) / sizeof(tab[0]);
    std::cout << "Pisz: ";
    pisz(tab, size);
    std::cout << "Test dla funkcji pisz: PASS" << std::endl;
}


void iota(int tab[], unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        tab[i] = i;
    }
}

void test_iota() {
    int tab[5];
    unsigned size = sizeof(tab) / sizeof(tab[0]);
    iota(tab, size);
    std::cout << "Tablica po wykonaniu funkcji iota: ";
    pisz(tab, size);
    std::cout << "Test dla funkcji iota: PASS" << std::endl;
}

void reverse(int* tab, size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        std::swap(tab[i], tab[size - i - 1]);
    }
}


void test_reverse() {
    int tab[] = { 1, 2, 3, 4, 5 };
    unsigned size = sizeof(tab) / sizeof(tab[0]);
    reverse(tab, size);
    std::cout << "Tablica po wykonaniu funkcji reverse: ";
    pisz(tab, size);
    std::cout << "Test dla funkcji reverse: PASS" << std::endl;
}


int dot_product(const int* tab1, const int* tab2, size_t size) {
    int result = 0;
    for (size_t i = 0; i < size; ++i) {
        result += tab1[i] * tab2[i];
    }
    return result;
}


void test_dot_product() {
    int tab1[] = { 1, 2, 3, 4, 5 };
    int tab2[] = { 1, 2, 3, 4, 5 };
    unsigned size = sizeof(tab1) / sizeof(tab1[0]);
    int expected_result = 55;
    int result = dot_product(tab1, tab2, size);
    std::cout << "Iloczyn skalarny: " << result << std::endl;
    if (result == expected_result) {
        std::cout << "Test dla funkcji dot_product: PASS" << std::endl;
    }
    else {
        std::cout << "Test dla funkcji dot_product: FAIL" << std::endl;
    }
}

int main() {
    test_suma();
    test_suma_result();
    test_pisz();
    test_iota();
    test_reverse();
    test_dot_product();

    return 0;
}