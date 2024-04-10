//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.1 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//01.12.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fin = fopen("input.txt", "rt");
	if (!fin) exit(1);
	int n, m, s = 1;
	char list[202][100];
	char mutual[202][100];
	char str[100];
	int mutcount = 0;
	char alsofriends[202][100];
	int alsocount = 0;
	char tmp[100];
	int fnd = 0;
	(void)fscanf(fin, "%d", &n);
	fgets(tmp, 100, fin);
	for (int i = 0; i < n; i++)
		fscanf(fin, "%s\n", list[i]);
	(void)fscanf(fin, "%d", &m);
	fgets(tmp, 100, fin);
	for (int i = 0; i < m; i++) {
		fscanf(fin, "%s\n", tmp);
		for (int j = 0; j < n; j++)
		{
			if (!strcmp(tmp,list[j]))
				fnd = 1;
		}
		if (fnd == 1) {
			strcpy(mutual[mutcount], tmp);
			mutcount++;
		}
		else {
			strcpy(alsofriends[alsocount], tmp);
			alsocount++;
		}
		fnd = 0;
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (strcmp(list[j], list[j + 1]) > 0) {
				strcpy(str, list[j]);
				strcpy(list[j], list[j + 1]);
				strcpy(list[j + 1], str);
			}
	for (int i = 1; i < mutcount; i++)
		for (int j = 0; j < mutcount - i; j++)
			if (strcmp(mutual[j], mutual[j + 1]) > 0) {
				strcpy(str, mutual[j]);
				strcpy(mutual[j], mutual[j + 1]);
				strcpy(mutual[j + 1], str);
			}
	for (int i = 1; i < alsocount; i++)
		for (int j = 0; j < alsocount - i; j++)
			if (strcmp(alsofriends[j], alsofriends[j + 1]) > 0) {
				strcpy(str, alsofriends[j]);
				strcpy(alsofriends[j], alsofriends[j + 1]);
				strcpy(alsofriends[j + 1], str);
			}

	fclose(fin);
	printf("Friends: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1) printf("%s, ", list[i]);
		else printf("%s", list[i]);
	}
	printf("\nMutual Friends: ");
	for (int i = 0; i < mutcount; i++)
	{
		if (i != mutcount - 1) printf("%s, ", mutual[i]);
		else printf("%s", mutual[i]);
	}
	printf("\nAlso Friend of: ");
	for (int i = 0; i < alsocount; i++)
	{
		if (i != alsocount - 1) printf("%s, ", alsofriends[i]);
		else printf("%s", alsofriends[i]);
	}
}
