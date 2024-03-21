#include <iostream>
#include <cmath>

double calculate_pi_approximation(int n) {
    double pi_approximation = 0.0;
    for (int j = 1; j <= n; ++j) {
        double term = (pow(-1, j + 1)) / (2 * j - 1);
        pi_approximation += 4 * term;
    }
    return pi_approximation;
}

int main() {
    int n = 1000000;
    double pi_value = 3.14159265358979323846;
    double result = calculate_pi_approximation(n);

    std::cout << "Wartość przybliżona: " << result << std::endl;
    std::cout << "Wartość liczby π: " << pi_value << std::endl;

    return 0;
}
