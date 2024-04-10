//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.2 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Выделение битового поля
//10.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	unsigned int x, N, K;
	(void)scanf("%d %d %d", &x, &N, &K);
	unsigned int msk = ((1 << (K - N + 1)) - 1) << N;
	x = (x & msk) >> N;
	printf("%d", x);
	return 0;
}