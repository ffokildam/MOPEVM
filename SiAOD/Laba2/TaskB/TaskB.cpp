//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба2.1
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//28.02.2024
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    sort(arr.begin(), arr.end());
    vector<int> ans(n);
    int l = 0, r = n - 1; 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            ans[l] = arr[i]; 
            l++; 
        } 
        else {
            ans[r] = arr[i]; 
            r--; 
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; 
    }

return 0;
}
