// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 7
// КТбо1-6, Кравченко Александр Андреевич
// TaskD
// 26.05.2024
#include <iostream>
#include <cmath>

using namespace std;

double length(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void sort(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3)
{
    if ((length(x1, y1, x2, y2) > length(x1, y1, x3, y3)) && (length(x1, y1, x2, y2) > length(x2, y2, x3, y3)))
    {
        swap(x1, x3);
        swap(y1, y3);
    }

    else if ((length(x1, y1, x3, y3) > length(x1, y1, x2, y2)) && (length(x1, y1, x3, y3) > length(x2, y2, x3, y3)))
    {
        swap(x1, x2);
        swap(y1, y2);
    }
}

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    sort(x1, y1, x2, y2, x3, y3);
    x4 = x2 + x3 - x1;
    y4 = y2 + y3 - y1;
    cout << x4 << ' ' <<  y4  << endl;
}
