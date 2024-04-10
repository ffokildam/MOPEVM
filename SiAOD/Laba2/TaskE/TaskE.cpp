//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба2.2
//КТбо1-6, Кравченко Александр Андреевич
//TaskE
//09.03.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int mid, const vector<int>& stalls, int cows) {
    int count = 1;
    int last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= mid) {
            last = stalls[i];
            count++;
            if (count == cows) return true;
        }
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> stalls(N);
    for (int i = 0; i < N; i++) {
        cin >> stalls[i];
    }

    int left = 0, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid, stalls, K)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;
    return 0;
}