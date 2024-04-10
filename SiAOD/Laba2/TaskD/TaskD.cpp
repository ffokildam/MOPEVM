//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба2.2
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//07.03.2024
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> nums(N);
    vector<int> res(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++) {
        int total = 0;
        for (int j = 0; j < i; j++) {
            int target = nums[i].first - nums[j].first;
            int lower = lower_bound(nums.begin(), nums.begin() + j, make_pair(target, -1)) - nums.begin();
            int upper = upper_bound(nums.begin(), nums.begin() + j, make_pair(target, N)) - nums.begin();
            total += upper - lower;
        }
        res[nums[i].second] = total;
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
