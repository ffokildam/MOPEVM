/*
    На ввод подаются 3 точки - выстрелы.
    Центр мишени - (0,0)
    Необходимо посчитать, сколько баллов будет заработано если:
    Расстояние до центра <=0.1 - 3 балла
    Расстояние до центра >0.1 и <=0.8 - 2 балла
    Расстояние до центра >0.8 и <1 - 1 балл
*/
#include <bits/stdc++.h>

using namespace std;

double countdist(double x,double y){
    return sqrt((x*x)+(y*y));
}

struct point{
    double x;
    double y;
    double dist;
};

int main(){
    point points[3];
    int result=0;

    for (int i = 0; i < 3; i++)
    {
        cin>>points[i].x>>points[i].y;
        points[i].dist = countdist(points[i].x,points[i].y);
        if(points[i].dist<=0.1f){
            result+=3;
        }
        else if((points[i].dist>0.1f)&&(points[i].dist<=0.8f)){
            result+=2;
        }
        else if((points[i].dist>0.8f)&&(points[i].dist<=1)){
            result++;
        }
    }
    
    cout<<result;
    return 0;
}