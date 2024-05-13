// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskG
// 05.05.2024
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9; 

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int b, e, w;
        cin >> b >> e >> w;
        --b; --e; 
        g[b].push_back({e, w});
        g[e].push_back({b, w});
    }

    vector<int> min_edge(n, INF);
    min_edge[0] = 0;
    set<pair<int, int>> q;
    q.insert({0, 0});
    vector<bool> used(n, false);
    int total_weight = 0;

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        used[v] = true;
        total_weight += min_edge[v];

        for (auto edge : g[v]) {
            int to = edge.first;
            int weight = edge.second;
            if (!used[to] && weight < min_edge[to]) {
                q.erase({min_edge[to], to});
                min_edge[to] = weight;
                q.insert({min_edge[to], to});
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}
