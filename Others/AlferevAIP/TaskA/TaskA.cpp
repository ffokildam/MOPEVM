#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>mass(n);
    for (int i = 0; i < n; i++)
    {
        cin>>mass[i];
    }
    sort(mass.begin(),mass.end());
    for (int i = 0; i < k; i++)
    {
        cout<<mass[i]<<' ';
    }
    return 0;
    
}