#include <iostream>
#include <cmath>

double calculate_expression(int n) {
    double sum = 0.0;
    for (int j = 1; j <= n; ++j) {
        double term = 1.0 / pow(2 * j - 1, 2);
        sum += term;
    }
    return sqrt(8 * sum);
}

int main() {
    int n = 1000000;
    double result = calculate_expression(n);

    std::cout << "Wartość przybliżona: " << result << std::endl;

    return 0;
}