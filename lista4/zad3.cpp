#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int kalkulacja(const std::vector<int>& kamienie) {
    int result = 0;
    for (int kamien : kamienie) {
        result ^= kamien;
    }
    return result;
}

void znajdzRuch(const std::vector<int>& kamienie) {
    int xorSum = kalkulacja(kamienie);

    if (xorSum == 0) {
        std::cout << "Rób co chcesz, strategia wygrywająca nie istnieje.\n";
        return;
    }

    for (size_t i = 0; i < kamienie.size(); ++i) {
        int new_xor = xorSum ^ kamienie[i];
        if (new_xor < kamienie[i]) {
            int kamienieDoPrzesuniencia = kamienie[i] - new_xor;
            std::cout << "Z rzędu nr " << (i + 1) << " zabierz " << kamienieDoPrzesuniencia << " kamienie.\n";
            return;
        }
    }
}

int main() {
    std::cout << "Program pomaga wygrać w grę Nim.\n"
        << "Podawaj liczby kamieni w kolejnych rzędach. Wpisz 'q' aby zakończyć.\n";

    std::vector<int> kamienie;
    std::string input;
    while (true) {
        std::cout << "Podaj liczby kamieni w kolejnych rzędach (lub 'q' aby zakończyć): ";
        std::getline(std::cin, input);

        if (input == "q" || input == "Q") {
            break;
        }

        std::istringstream iss(input);
        int kamien;
        while (iss >> kamien) {
            kamienie.push_back(kamien);
        }

        znajdzRuch(kamienie);
        kamienie.clear();
    }

    return 0;
}
