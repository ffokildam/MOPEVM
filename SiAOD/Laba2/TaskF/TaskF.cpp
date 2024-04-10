//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба2.2
//КТбо1-6, Кравченко Александр Андреевич
//TaskF
//07.03.2024
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const long double eps =1e-10;

long double eq(long double x){
    return x*x +sqrt(x);
}

int main(){
    long double c, l = 0, r = 1e15,m;
    cin>>c;
    while(fabs(r-l)>eps){
        m = (r+l)/2.0;
        if(eq(m)-c<0) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(7)<<r<<endl; 
    return 0;
}
