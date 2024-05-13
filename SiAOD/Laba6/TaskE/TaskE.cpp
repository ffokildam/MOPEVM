#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> mass(n);
    for (int i = 0; i < n; i++)
    {
        cin>>mass[i];
    }

    int i = 0;
    int allmin = 1e9;
    for (int j = k; j <= n; j++)
    {
        i = j-k;
        while(i<j){
            allmin = min(allmin,mass[i]);
            i++;
        }
        cout<<allmin<<' ';
        allmin = 1e9;
    }
}