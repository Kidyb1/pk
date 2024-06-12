#include <iostream>
#include <vector>
#include <complex>
#include "timer.h"


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int silnia(int n) {
    if (n == 0)
        return 1;
    return n * silnia(n - 1);
}

int fibonacci(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    
    std::vector<int> vecInt = { 1, 2, 3, 4, 5 };
    std::vector<double> vecDouble = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::vector<std::complex<double>> vecComplex = { {1, 2}, {3, 4}, {5, 6} };

    std::cout << "Vector of ints: " << vecInt << std::endl;
    std::cout << "Vector of doubles: " << vecDouble << std::endl;
    std::cout << "Vector of complex numbers: " << vecComplex << std::endl;

   
    Timer timer;

   
    for (int i = 30; i >= 0; i--)
        std::cout << i << "! = " << silnia(i) << std::endl;

    for (int i = 0; i <= 45; i++)
        std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << "\n";

    std::cout << "Koniec programu\n";

    double elapsed = timer.get_elapsed_seconds();
    std::cout << "Czas wykonania: " << elapsed << " sekund" << std::endl;

    return 0;
}
