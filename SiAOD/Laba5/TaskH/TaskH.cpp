// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskH
// 05.05.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
};

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);  
    }
    return parent[x];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    int u, v;

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    vector<Edge> result;
      
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
   
    for (auto& e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            result.push_back(e);
            unite(parent, rank, e.u, e.v);
            if (result.size() == N - 1) break;  
        }
    }

    for (auto& e : result) cout << e.u << " " << e.v << endl;

    return 0;
}