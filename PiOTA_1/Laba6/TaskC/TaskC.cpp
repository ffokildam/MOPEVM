//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.1 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//13.12.2023

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct{
    double x;
    double y;
}point;

/*
Функция dist используется для расчёта расстояния между двумя точками на плоскости
На вход получает две переменных типа point
Возвращает double - расстояние между точками.
*/
double dist(point,point);

int main(){
    point points[100];
    int n;
    double per,maxper = 0;

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>points[i].x>>points[i].y;
    }

    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = i+2; k < n; k++)
            {
                per = dist(points[i], points[j]) + dist(points[i], points[k]) + dist(points[j], points[k]);
                if(per>maxper) maxper = per;
            }
            
        }
        
    }
    cout<<setprecision(15)<<maxper;
}

double dist(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
