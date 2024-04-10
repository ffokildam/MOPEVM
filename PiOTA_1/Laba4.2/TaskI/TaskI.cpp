//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.2 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskI
//22.11.2023
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char str[20001] = "";
    char str2[20001] = "";
    char str3[20001] = "";
    gets_s(str);
    strcpy(str2, str);
    int n;
    scanf("%d", &n);
    if (n > 0) {
        int j = 0;
        while (j < n - 1 && strlen(str) < 1023) {
            strcat(str, str2);
            j++;
        }
        printf("%.1023s", str);
    }
    else {
        if (strlen(str) % (-n) == 0) {
            str2[strlen(str) / (-n)] = '\0';
            for (int i = 0; i < (-n); i++) strcat(str3, str2);
            if (!strcmp(str, str3)) printf("%s", str2);
            else printf("NO SOLUTION");
        }
        else printf("NO SOLUTION");
    }
}