//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//ДЗ2 - Реализация и анализ примитивно-рекурсивной функции.
//КТбо1-6, Кравченко Александр Андреевич
//11.04.2024

#include <iostream>
#include <conio.h>
#include <math.h>
#include <limits>

typedef unsigned long long ull;

// Рекурсивная функция PrimRecursive
// Принимает на вход два числа - x, y - переменные рекурсии
// Реализует рекурсивное вычисление функции
// На каждом шаге рекурсии выводит на экран строку, иллюстрирующую вычисление
// Возвращает одно число - результат работы рекурсии
ull PrimRecursive(ull, ull);

int main() {
    setlocale(LC_ALL, "Russian");

    ull x, y, res;
    char cont;
    bool limited;
    std::cout << "Схема рекурсии:\nf(0,x) = g(x) = x\nf(y+1,x) = h(y,f(y,x),x) = x*f(y,x)\n\n";

    do {
        limited = 0;
        std::cout << "Введите y: ";
        std::cin >> y;

        std::cout << "Введите x: ";
        std::cin >> x;

        if (pow(x, y + 1) < ULLONG_MAX) {
            res = PrimRecursive(x, y);
            std::cout << "Вывод ПРФ: " << res;

            std::cout << "\n\nНажмите любую клавишу, чтобы продолжить\nДля выхода нажите клавишу ESC на клавиатуре";
            cont = _getch();
            std::cout << "\n\n";
        }
        else {
            std::cout << "\nРезультат ПРФ от введённых вами чисел выходит за пределы области значений функции.\nПопробуйте ввести другие переменные.\n";
        }
    } while (cont != 27 || limited);

    exit(0);
}

ull PrimRecursive(ull x, ull y) {
    if (y == 0) {
        std::cout << "f(0," << x << ") = g(" << x << ") = " << x << "\n";
        return x;
    }
    ull curr = PrimRecursive(x, y - 1);
    ull next = pow(x, y + 1);
    std::cout << "f(" << y << "," << x << ") = h(" << y - 1 << "," << "f(" << y - 1 << "," << x << ")," << x << ") = h(" << y - 1 << "," << curr << "," << x << ") = " << next << '\n';
    return next;
}