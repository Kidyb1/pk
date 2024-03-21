#include <iostream>
#include <cmath>

double method_a(int i) {
    double t = 1 / sqrt(3);
    for (int j = 0; j < i; ++j) {
        t = ((sqrt(t * t + 1) - 1) / t);
    }
    return 6 * pow(2, i) * t;
}

double method_b(int i) {
    double t = 1 / sqrt(3);
    for (int j = 0; j < i; ++j) {
        t = t / (sqrt(t * t + 1) + 1);
    }
    return 6 * pow(2, i) * t;
}

int main() {
    std::cout << "i\tMethod A\tMethod B" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (int i = 0; i <= 30; ++i) {
        double approx_pi_a = method_a(i);
        double approx_pi_b = method_b(i);
        std::cout << i << "\t" << approx_pi_a << "\t" << approx_pi_b << std::endl;
    }

    return 0;
}