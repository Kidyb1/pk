#include <iostream>
#include <cmath>

double root(double (*f)(double), double a, double b, double tolerance = 1e-10) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0) {
        std::cerr << "Brak zmiany znaku na zadanym przedziale." << std::endl;
        return NAN; 
    }

    double c = 0.0;
    while (std::abs(b - a) > tolerance) {
        c = (a + b) / 2;
        double fc = f(c);
        if (std::abs(fc) < tolerance) {
            break;
        }
        if (fc * fa < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }

    return c;
}

double cos_minus_x(double x) {
    return std::cos(x) - x;
}

double cos_minus_half(double x) {
    return std::cos(x) - 0.5;
}

int main() {
    double root_1 = root(cos_minus_x, 0, 2, 1e-6);
    double root_2 = root(cos_minus_half, 0, 1.5, 1e-6);

    std::cout << "Pierwiastek równania cos(x) - x = 0 w przedziale [0, 2] = " << root_1 << std::endl;
    std::cout << "Pierwiastek równania cos(x) - 0.5 = 0 w przedziale [0, 1.5] = " << root_2 << std::endl;

    return 0;
}
