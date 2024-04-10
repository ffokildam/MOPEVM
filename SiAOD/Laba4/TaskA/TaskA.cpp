//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 4
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//27.03.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> dp(n,INT_MAX);
    dp[0] = 0; 

    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + abs(heights[i] - heights[i - 1]));

        if (i >= 2) {
            dp[i] = min(dp[i], dp[i - 2] + 3 * abs(heights[i] - heights[i - 2]));
        }
    }

    cout << dp[n - 1] << endl; 

    return 0;
}