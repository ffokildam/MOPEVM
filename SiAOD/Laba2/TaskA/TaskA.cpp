//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//28.02.2024
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    int playersum=0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < n/2; i++)
    {
        playersum+=nums[0];
        nums.erase(nums.begin());
    }
    auto dealersum = reduce(nums.begin(),nums.end());
    cout<<playersum-dealersum;
}