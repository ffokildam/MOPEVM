// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskD
// 13.05.2024

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> mass(n);
    if(!n){
        cout<<0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>mass[i];
    }

    int maxPP = 0;

    sort(mass.begin(), mass.end());

    int i = 0;
    int s;
    if(mass.size()>1)
        s = mass[0] + mass[1];
    else
        s = mass[0];
    int summ = s;

    for (int j = 2; j < n; j++)
    {
        
        s += mass[j];
        if ((mass[i] + mass[i + 1]) < mass[j])
        {

            while ((mass[i] + mass[i + 1]) < mass[j])
            {
                s -= mass[i];
                i++;
            }

        }
        summ = max(summ, s);

    }
    if(mass.size()>1)
       summ = max(summ,(mass[n-1]+mass[n-2]));
    cout << summ;
}