//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.1 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//30.11.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fin = fopen("input.txt", "rt");
	if (!fin)
		exit(1);
	char s[102];
	int count = 0;
	int ended = 0;
	while (!ended) {
		fgets(s, 102, fin);
		if (feof(fin))
			ended = 1;
		else if (!ended)
			if (s[0] == '\n') count++;
	}
	printf("%d", count);
	fclose(fin);
	return 0;
}
