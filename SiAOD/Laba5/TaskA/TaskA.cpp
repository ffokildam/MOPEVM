//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба 5
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//15.04.2024
#include <bits/stdc++.h>

using namespace std;

int A[101][101];
bool visits[101];

void DFS(int k, int n){
    visits[k] = true;
    for (int i = 1; i <= n; i++)
    {
        if(A[k][i] && !visits[i]) DFS(i,n);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    
    int x,y;
    while(true){
        cin>>x;
        if(!x) break;
        cin>>y;
        A[x][y] = 1;
    }
    DFS(k,n);
    for (int i = 1; i <=n; i++)
    {
        if(!visits[i]){
            cout<<"No";
            return 0;
        }

    }
    
    cout<<"Yes";
    return 0;

}