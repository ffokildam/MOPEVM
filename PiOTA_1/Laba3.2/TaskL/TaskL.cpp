//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба3.2 - Массивы, указатели, строки
//КТбо1-6, Кравченко Александр Андреевич
//TaskL
//08.11.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    char a[1001][11];
    char gp[101];
    char gp1[101];
    int maincount = 0;
    int count1 = 0;
    int count2 = 0;
    bool fd1 = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        (void)scanf("%s", a[i]);
    }
    //Удаление повторяюшихся элементов из массива
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ) {
            int k = 0;
            while (a[i][k] != '\0' && a[j][k] != '\0' && a[i][k] == a[j][k]) {
                k++;
            }
            if (a[i][k] == '\0' && a[j][k] == '\0') {
                int l = 0;
                while (a[j][l] != '\0') {
                    a[j][l] = a[n - 1][l];
                    l++;
                }
                a[n - 1][0] = '\0';
                n--;
            }
            else {
                j++;
            }
        }
    }
    (void)scanf("%s", gp);
    //Собственно сам подсчет
    for (int i = 0; i < n; i++)
    {
        for (int f = 0; (gp[f] == ' ') || (gp[f] > 91 && gp[f] < 123); f++)
        {
            gp1[f] = gp[f];
        }
        for (int j = 0; (a[i][j] == ' ') || (a[i][j] > 91 && a[i][j] < 123); j++)
        {
            for (int y = 0; ((gp1[y] == ' ') || (gp1[y] > 91 && gp1[y] < 123)) && fd1==false ; y++)
            {
                if (gp1[y] == a[i][j]) {
                    count1++;
                    gp1[y] = ' ';
                    fd1 = true;
                }
            }
            count2++;
            fd1 = false;
        }
        if (count1 == count2) maincount++;
        count1 = 0;
        count2 = 0;
    }
    printf("%d", maincount);

}