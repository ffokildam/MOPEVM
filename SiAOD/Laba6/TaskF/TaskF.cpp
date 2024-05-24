// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskF
// 19.05.2024

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> tsht(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>tsht[i];
    }
    
    int m;
    cin>>m;

    vector<int> trsr(m);
    for (int i = 0; i < m; i++)
    {
        cin>>trsr[i];
    }

    
    int i = 0, j = 0;
    int minDiff = 1e9;
    int currTsht = -1, currTrsr = -1;

    while (i < n && j < m) {
        int diff = abs(tsht[i] - trsr[j]);
        if (diff < minDiff) {
            minDiff = diff;
            currTsht = tsht[i];
            currTrsr = trsr[j];
        }
        if (tsht[i] < trsr[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    cout << currTsht << " " << currTrsr << endl;

    return 0;
}

    
