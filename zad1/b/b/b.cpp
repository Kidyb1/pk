#include <iostream>
#include <cmath>

double calculate_pi_product(int n) {
    double pi_product = 1.0;
    for (int j = 1; j <= n; ++j) {
        double term = (4 * pow(j, 2)) / (4 * pow(j, 2) - 1);
        pi_product *= term;
    }
    return 2 * pi_product;
}

int main() {
    int n = 1000000;
    double pi_value = 3.14159265358979323846; 
    double result = calculate_pi_product(n);

    std::cout << "Wartość przybliżona: " << result << std::endl;
    std::cout << "Wartość liczby π: " << pi_value << std::endl;

    return 0;
}