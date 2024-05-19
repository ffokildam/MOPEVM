// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskE
// 19.05.2024

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> mass(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mass[i];
    }

    list<int> min;

    for (int i = 0; i < n; ++i)
    {

        if (!min.empty() && min.front() == i - k)
        {
            min.pop_front();
        }

        while (!min.empty() && mass[min.back()] >= mass[i])
        {
            min.pop_back();
        }

        min.push_back(i);

        if (i >= k - 1)
        {
            cout<<mass[min.front()]<<endl;
        }
    }


    return 0;
}