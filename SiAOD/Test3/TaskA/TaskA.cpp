//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Тест 3
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//30.03.2024
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    set <int> money;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        if(money.contains(temp)) cout<<"NO"<<endl;
        else{
            money.insert(temp);
            cout<<"YES"<<endl;
        }
    }
    
}