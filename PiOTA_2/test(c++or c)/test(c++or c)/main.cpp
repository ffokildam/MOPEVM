#include <iostream>
#include <string>
#include <windows.h>
#include <regex>

struct SubstTable {
    std::string Sample;
    std::string Replacement;
    bool endPoint;
};

int inputValid(std::string input) {
    const std::regex validSymbols("^(a|b|c|e)+$");
    if (input.empty()) return 2;
    if (!regex_match(input, validSymbols)) return 1;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string input;
    char cont;

    do {
        if (cont != 1)
            std::cout << "������� ������� �����: ";

        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });

        switch (inputValid(input)) {
        case 0:
            break;
        case 1:
            cont = 1;
            std::cout << "�������� ������������������ �� ������������� �������� {a,b,c,e}\n���������� ������ ������ ������������������: ";
            break;
        case 2:
            cont = 1;
            std::cout << "�������� ������������������ �������� ������\n���������� ������ ������ ������������������: ";
            break;

        }
    } while (cont != 27);
}