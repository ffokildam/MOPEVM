//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.2 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskH
//22.11.2023
#include <iostream>
#include <cmath>

using namespace std;

/*Подпрограмма fMD выполняет пошаговый перебор всех возможных вариантов разложения камней.
* Функция делает 2 рекурсивных вызова, тем самым рассматривает вариант добавления камная либо в одну из двух куч, а затем возвращает минимум из вызовов.
* На вход получает параметры:
* weights - ссылка на массив всех масс камней в куче.
* i - позиция камня в массиве
* sum1 - сумма первой кучи
* sum2 - сумма второй кучи
*/
int fMD(const int(&)[18], int, int, int, int);

int main() {
    int N;
    cin >> N;
    int weights[18];
    for (int i = 0; i < N; i++) cin >> weights[i];
    int minDifference = fMD(weights, 0, 0, 0,N);
    cout << minDifference << endl;
}
int fMD(const int(&weights)[18], int i, int sum1, int sum2, int N) {
    if (i == N) return abs(sum1 - sum2);
    return min(fMD(weights, i + 1, sum1 + weights[i], sum2, N), fMD(weights, i + 1, sum1, sum2 + weights[i], N));
}