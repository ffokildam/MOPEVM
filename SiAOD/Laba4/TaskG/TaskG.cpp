//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 4
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//14.04.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i * i * i <= N; ++i) {
        int cube = i * i * i;
        for (int j = cube; j <= N; ++j) {
            dp[j] = min(dp[j], dp[j - cube] + 1);
        }
    }

    cout << dp[N];

    return 0;
}
