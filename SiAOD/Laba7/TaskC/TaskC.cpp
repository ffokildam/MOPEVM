// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 7
// КТбо1-6, Кравченко Александр Андреевич
// TaskC
// 26.05.2024
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int R, X, Y;
    std::cin >> R >> X >> Y;

    double reflectedX = X;
    double reflectedY = 2 * R - Y;

    double hitX = static_cast<double>(R * reflectedX) / reflectedY;

    std::cout << std::fixed << std::setprecision(2) << std::abs(hitX) << std::endl;

    return 0;
}
