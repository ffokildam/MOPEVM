// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskI
// 05.05.2024
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, s;
vector<vector<int>> capacity;
vector<int> parent;

bool bfs(int source, int sink) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next = 0; next < parent.size(); ++next) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return false;
}

int maxFlow(int source, int sink) {
    int flow = 0;
    int new_flow;

    while (new_flow = bfs(source, sink)) {
        flow += new_flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    cin >> n >> s;

    int source = 0, sink = n + s + 1;
    capacity.resize(n + s + 2, vector<int>(n + s + 2, 0));
    parent.resize(n + s + 2);

    for (int i = 1; i <= n; ++i) capacity[source][i] = 1;
    
    for (int i = 1; i <= s; ++i) capacity[n + i][sink] = 1;
    
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= n; ++j) {
            int can_do;
            cin >> can_do;
            if (can_do == 1) {
                capacity[j][n + i] = 1;
            }
        }
    }

    cout << maxFlow(source, sink) << endl;

    return 0;
}
