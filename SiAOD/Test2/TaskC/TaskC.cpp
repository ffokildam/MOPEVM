//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//КР2
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//16.03.2024
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    int p,d=1000000000,q;
    cin>>n>>x;
    vector<int> mass;

    for (int i = 0; i < n; i++)
    {
       int temp;
       cin>>temp;
       mass.push_back(temp);
    }
    sort(mass.begin(),mass.end());
    for (int i = 0; i < n; i++)
    {
        int key = mass[i];
        int found1 = lower_bound(mass.begin(),mass.end(),x-key)-mass.begin();
        int found2 = upper_bound(mass.begin(),mass.end(),x-key)-mass.begin();
        if(found1 == mass.size()){
            found1--;
            while(mass[found1]==key) found1--;
        }
        if(found2 == mass.size()) {
            found2--;
            while(mass[found2]==key) found2--;
        }
        int found;
        if(mass[found1]>mass[found2] && x -(key+mass[found1])>=0) found = found1;
        else if(x-(key+mass[found2])>=0) found = found2;
        else found=found2;  
        if(x -(key+mass[found])<d){
            p = key;
            q = mass[found];
            d = x -(key+mass[found1]);
        }
    }
    cout<<p<<' '<<q<<' '<<d<<endl;
    
}