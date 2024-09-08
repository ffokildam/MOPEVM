// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 7
// КТбо1-6, Кравченко Александр Андреевич
// TaskA
// 26.05.2024
#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

int turnDirection(const Point &a, const Point &b, const Point &c) {
    double crossProduct = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    if (crossProduct > 0) return 1; 
    else if (crossProduct < 0) return -1; 
    return 0; 
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    int leftTurnCount = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (turnDirection(points[i - 1], points[i], points[i + 1]) == 1) {
            leftTurnCount++;
        }
    }

    std::cout << leftTurnCount << std::endl;
    return 0;
}
