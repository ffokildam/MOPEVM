//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 4
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//31.03.2024
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> in(N);
    vector<int> dp(N - 1);

    for (int i = 0; i < N; i++)
        cin >> in[i];

    sort(in.begin(), in.end());

    dp[0] = in[1] - in[0];
    if (N > 2)
        dp[1] = in[2] - in[0];

    for (int i = 3; i < N; i++)
        dp[i - 1] = in[i] - in[i - 1] + min(dp[i - 3], dp[i - 2]);

    cout << dp[N - 2] << endl;
}