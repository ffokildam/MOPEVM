//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 4
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//14.04.2024
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> a(n+1, vector<int>(k+n, 0));

    a[0][k] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k-1+n; j++) {
            a[i][j] = a[i-1][j+1];
            if (j - 1 >= 0) {
                a[i][j] += a[i - 1][j - 1];
            }
        }
        if (i != n) {
            a[i][0] = 0;
        }
    }

    cout << a[n][0];

    return 0;
}
