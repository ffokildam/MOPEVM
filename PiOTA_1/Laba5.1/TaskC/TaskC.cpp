//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.1 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//29.11.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ull n, m;
	ull mass1[200000];
	scanf("%llu %llu", &n, &m);
	for (ull i = 0; i < n; i++)
	{
			scanf("%llu", &mass1[i]);
	}
	for (ull i = 0; i < m; i++)
	{
		ull t;
		scanf("%llu", &t);
		ull left = 0, right = n;
		ull k, flag = 0;
		while ((left < right) && (!flag))
		{
			k = (left + right) / 2;
			if (mass1[k] == t)
				flag = 1;
			else if (mass1[k] < t)
				left = k + 1;
			else
				right = k;

		}
		if (flag)
			printf("YES ");
		else
			printf("NO ");
		fclose(stdin);
		fclose(stdout);
	}
}
