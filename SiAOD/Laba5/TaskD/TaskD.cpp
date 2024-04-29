// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 5
// КТбо1-6, Кравченко Александр Андреевич
// TaskD
// 28.04.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int inf = 100000000;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int begin, end;
    cin >> begin >> end;
    vector<int> dist(n, inf), parent(n, -1);
    vector<bool> visited(n, false);
    int min_dist;
    int min_ind;
    dist[begin - 1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min_dist = inf;
        min_ind = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_ind = j;
            }
        }
        if (min_ind == -1)  break;
        visited[min_ind] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && graph[min_ind][i] != 0 && dist[min_ind] != inf && dist[min_ind] + graph[min_ind][i] < dist[i])
            {
                dist[i] = dist[min_ind] + graph[min_ind][i];
                parent[i] = min_ind;
            }
        }
    }
    vector<int> path;
    int current = end - 1;
    while (current != -1)
    {
        path.push_back(current + 1);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    if (dist[end - 1] == inf)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << dist[end - 1] << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
