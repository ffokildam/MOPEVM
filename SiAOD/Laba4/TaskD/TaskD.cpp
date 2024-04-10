//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 4
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//07.04.2024
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
const double diag = 100 * sqrt(2);

int main() {
    
    vector<vector<double>> dp(MAXN, vector<double>(MAXN));
    vector<vector<bool>> routes(MAXN, vector<bool>(MAXN));
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        routes[x][y] = true;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = 123456789;

    dp[0][0] = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i < N)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 100);
            if (j < M)
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 100);
            if (i < N && j < M && routes[i + 1][j + 1])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 100 * sqrt(2));
        }
    }

    cout << round(dp[N][M]) << endl;

    return 0;
}
