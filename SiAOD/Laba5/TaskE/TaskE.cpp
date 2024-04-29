// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskE
// 28.04.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int inf = 10000000;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        s--, e--;
        dist[s][e] = dist[e][s] = l;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int max_dist = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist[i][j] < inf) max_dist = max(max_dist, dist[i][j]);
    cout << max_dist << endl;
    return 0;
}
