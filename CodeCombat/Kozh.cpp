#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> math(n + 1), code(n + 1);
    vector<pair<int, int>> pairs(m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> code[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> math[i];
    }
 
    for (int i = 0; i < m; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }
 
    pair<int, int> result = make_pair(0, 0);
    int pair_score = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int score1 = code[pairs[j].first - 1] + math[pairs[j].second - 1];
            int score2 = code[pairs[i].first - 1] + math[pairs[i].second - 1];
            if (score1 + score2 >= pair_score)
            {
                if (pairs[j].first != pairs[i].first && pairs[j].first != pairs[i].second && pairs[j].second != pairs[i].first && pairs[j].second != pairs[i].second)
                {
                    pair_score = score1 + score2;
                    result = make_pair(i, j);
                }
            }
        }
    }
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int score1 = code[pairs[j].first - 1] + math[pairs[j].second - 1];
            int score2 = code[pairs[i].first - 1] + math[pairs[i].second - 1];
            if (score1 + score2 >= pair_score)
            {
                if (pairs[j].first != pairs[i].first && pairs[j].first != pairs[i].second)
                {
                    pair_score = score1 + score2;
                    result = make_pair(i, j);
                    break;
                }
            }
        }
    }
 
    if (result.first == 0 || result.second == 0) cout << 0;
    else cout << min(result.first + 1, result.second + 1) << ' ' << max(result.first + 1, result.second + 1);
 
    return 0;
}