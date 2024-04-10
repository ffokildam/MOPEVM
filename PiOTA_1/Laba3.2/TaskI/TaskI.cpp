//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба3.1 - Массивы, указатели, строки
//КТбо1-6, Кравченко Александр Андреевич
//TaskI
//08.11.2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	char a[4];
	char b[4];
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == b[i]) count1++;
		for (int j = 0; j < 4; j++)
		{
			if (a[i] == b[j] && i != j) count2++;
		}
	}
	cout << count1 << ' ' << count2;
}