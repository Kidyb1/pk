#include <iostream>

double downd(int N) {
    double sum = 0.0;
    for (int i = 1; i <= N; ++i) {
        sum += 1.0 / i;
    }
    return sum;
}

double upd(int N) {
    double sum = 0.0;
    for (int i = N; i >= 1; --i) {
        sum += 1.0 / i;
    }
    return sum;
}
float downf(int N) {
    float sum = 0.0;
    for (int i = 1; i <= N; ++i) {
        sum += 1.0 / i;
    }
    return sum;
}

float upf(int N) {
    float sum = 0.0;
    for (int i = N; i >= 1; --i) {
        sum += 1.0 / i;
    }
    return sum;
}

void compare_sums_double(int N) {
    double down_result = downd(N);
    double up_result = upd(N);
    std::cout << "N = " << N << ", double:" << std::endl;
    std::cout << "down(N) = " << down_result << std::endl;
    std::cout << "up(N) = " << up_result << std::endl;
    std::cout << "Difference = " << up_result - down_result << std::endl;
}

void compare_sums_float(int N) {
    float down_result = downf(N);
    float up_result = upf(N);
    std::cout << "N = " << N << ", float:" << std::endl;
    std::cout << "down(N) = " << down_result << std::endl;
    std::cout << "up(N) = " << up_result << std::endl;
    std::cout << "Difference = " << up_result - down_result << std::endl;
}

int main() {
    std::cout.precision(10);

 
    compare_sums_double(100);
    compare_sums_double(100000);
    compare_sums_double(100000000);

  
    compare_sums_float(100);
    compare_sums_float(100000);
    compare_sums_float(100000000);
    //dla największej precyzji najlepiej od małych do dużych 
    return 0;
}