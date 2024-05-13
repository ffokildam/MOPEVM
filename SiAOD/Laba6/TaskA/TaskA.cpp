// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskA
// 12.05.2024

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

bool KMP(const string &pattern, const string &text) {
    string s = pattern + '#' + text;
    vector<int> pi = prefix(s);
    for (int i = pattern.size() + 1; i < s.size(); ++i) {
        if (pi[i] == pattern.size())
            return true;
    }
    return false;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;
    if (KMP(pattern, text))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
