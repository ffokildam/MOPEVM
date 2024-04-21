//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 5
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//21.04.2024
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int n;

void dfs(int v, int p = -1) {
    visited[v] = true;
    for (int u : g[v]) {
        if (u == p) continue;
        if (visited[u]) {
            cout << "NO";
            exit(0);
        }
        dfs(u, v);
    }
}

int main() {
    cin >> n;
    g.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x) g[i].push_back(j);
        }
    }

    dfs(0);

    for (bool v : visited) {
        if (!v) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
