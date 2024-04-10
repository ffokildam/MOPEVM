//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.2 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Установить бит
//09.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long ll;

int main() {
    ll a, k;
    scanf("%lld %lld", &a, &k);
    ll mask = 1;
    mask = mask << k;
    a = a | mask;
    printf("%lld", a);

    return 0;
}



