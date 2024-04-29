// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskF
// 28.04.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int inf = 10000000;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> gh(n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = inf;
            }
        }
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (graph[i][k] < inf && graph[k][j] < inf)  graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    for (int i = 0; i < n; i++) cin >> gh[i];
    int min_dist = inf;
    int pos = 0;
    int total_dist = 0;
    int dist = 0;
    for (int i = 0; i < n; i++) 
    {
        total_dist = 0;
        for (int j = 0; j < n; j++) 
        {
            if (graph[i][j] == inf) dist = 10000;
            else dist = graph[i][j];
            total_dist += (dist * gh[j]);
        }
        if (total_dist < min_dist) 
        {
            min_dist = total_dist;
            pos = i;
        }
    }
    cout << pos + 1 << " " << min_dist << endl;
    return 0;
}
