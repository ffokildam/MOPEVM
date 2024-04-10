//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.2 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Инвертировать и сбросить биты
//09.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned int a, k, m;
	(void)scanf("%u %u %u", &a, &k, &m);
	unsigned int msK = 1 << k;
	unsigned int msM = 1 << m;
	a ^= msK;
	a &= ~msM;
	printf("%d", a);
	return 0;
}