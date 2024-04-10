//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Дополнительные задания для тренировки
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//03.01.2024
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

struct hits{
    double x;
    double y;
};

int main(){
    hits hit;
    int hittargets[5] = {};
    int count = 0;
    for (int i = 0; i < 5; i++){
        cin>>hit.x>>hit.y;
        int xT = 0;
        bool isHit = 0;
        for (int i = 0; i < 5 && !isHit; i++)
        {
            if(pow((xT-hit.x),2) + pow(0-hit.y,2) <=100){
                hittargets[i]=1;
                isHit = 1;
            }
            xT+=25; 
        }
    }
    int sum = 0;
    for(auto c: hittargets){
        sum+=c;
    }

    cout<<sum;
}