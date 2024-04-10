//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.1 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//28.11.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fin = fopen("input.txt", "rt");
	FILE* fou = fopen("output.txt", "wt");				
	if (!fin) exit(1);
	int n,s=1;
	(void)fscanf(fin, "%d", &n);
	while (s <= n) {
		n -= s;
		s++;
	}
	fprintf(fou, "%d", s - 1);
	fclose(fin);
	fclose(fou);
}
