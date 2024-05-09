#include <iostream>
#include <vector>

class VectorDotProduct {
private:
    std::vector<double> vec;

public:
    
    VectorDotProduct(const std::vector<double>& v) : vec(v) {}

    
    double operator*(const std::vector<double>& other) const {
        double result = 0.0;
        
        if (vec.size() != other.size()) {
            std::cerr << "wektory muyszą mieć tą samą długość" << std::endl;
            return result;
        }
        
        for (size_t i = 0; i < vec.size(); ++i) {
            result += vec[i] * other[i];
        }
        return result;
    }
};

int main() {
    std::vector<double> v = { 2.0, 2.0, 2.0 };
    std::vector<double> w = { 3.0, 3.0, 3.0 };

    VectorDotProduct vd_v(v);
    double dot_product = vd_v * w;

    std::cout << "iloczyn skalarny " << dot_product << std::endl;

    return 0;
}
