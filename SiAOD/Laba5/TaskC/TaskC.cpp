//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 5
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//21.04.2024
#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];
int color[105];

bool dfs(int v, int c) {
    color[v] = c;
    for(int u : g[v]) {
        if(color[u] == -1) {
            if(!dfs(u, 1 - c)) {
                return false;
            }
        } else if(color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(color, -1, sizeof color);
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
