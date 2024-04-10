// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Тест 3
// КТбо1-6, Кравченко Александр Андреевич
// TaskB
// 30.03.2024
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    multimap<int, int> ants;
    int n, x, m;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;   
        cin >> temp1 >> temp2;
        ants.insert(pair<int,int>(temp2,temp1));
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int frog;
        cin >> frog;
        auto found = *ants.lower_bound(frog);
        auto found1 = ants.lower_bound(frog);
        if(found1!=ants.end())
            ants.erase(found.first);
    }
    int res = 0;
    for (auto c : ants)
    {
        res += c.second;
    }
    cout << res;
}