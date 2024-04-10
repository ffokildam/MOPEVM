//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.1 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Задание F
//03.10.2023
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;
int main() {
	int hh, mm, Rh, Rm, RmT;
	scanf("%d:%d", &hh, &mm);
	scanf("%d %d", &Rh, &Rm);
	RmT = Rm + mm;
	(mm + Rm > 59) ? Rm = (Rm + mm) % 60 : Rm = Rm + mm;
	(Rm == RmT) ? Rh = Rh : Rh += 1;
	(hh + Rh > 23) ? Rh = (Rh + hh) % 24 : Rh = Rh + hh;
	(Rh < 10) ? (Rm < 10) ? cout << '0' << Rh << ':' << '0' << Rm : cout << '0' << Rh << ':' << Rm : (Rm < 10) ? cout << Rh << ':' << '0' << Rm : cout << Rh << ':' << Rm;
}