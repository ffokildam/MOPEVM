#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int B, N;
    cin >> B >> N;

    vector<int> denominations(N);
    for (int i = 0; i < N; ++i) {
        cin >> denominations[i];
    }

    // Создаем массив dp и заполняем его большими значениями
    vector<int> dp(B + 1, INT_MAX);
    dp[0] = 0; // Для суммы 0 требуется 0 купюр

    // Обновляем dp для каждой купюры
    for (int i = 0; i < N; ++i) {
        for (int j = denominations[i]; j <= B; ++j) {
            if (dp[j - denominations[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - denominations[i]] + 1);
            }
        }
    }

    // Результат находится в dp[B]
    cout << dp[B] << endl;

    return 0;
}
