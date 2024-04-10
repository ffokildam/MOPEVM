//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//КР2
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//16.03.2024
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> friends_mmr;
    int friends_n;
    cin>>friends_n;
    for (int i = 0; i < friends_n; i++)
    {
        int temp;
        cin>>temp;
        friends_mmr.push_back(temp);
    }

    vector<int> vasya_mmr;
    int vasya_n;
    cin>>vasya_n;
    for (int i = 0; i < vasya_n; i++)
    {
        int temp;
        cin>>temp;
        vasya_mmr.push_back(temp);
    }

    cout<<endl;
    int previ1=-1;
    for (int i = 0; i < vasya_mmr.size(); i++)
    {
        
        int i1 = lower_bound(friends_mmr.begin(),friends_mmr.end(),vasya_mmr[i]) -friends_mmr.begin();
      
            cout<<i1<<endl;
        
    }
}