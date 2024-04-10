//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.2 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskH
//07.12.2023
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<windows.h>
#include<string.h>
#include<io.h>

int main() {
    char strF[21]; 
    char* ptrF;
    
    wchar_t str1[21];
    wchar_t* ptr1;
   
    wchar_t strC[21]; 
    wchar_t* ptrC;
   
    wchar_t res[42] = L"";
    

    FILE* fin = fopen("input.txt", "rt");
    FILE* fout = fopen("output.txt", "wt, ccs = UTF-16LE");
    if (!fin || !fout) {
        exit(1);
    }

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    _setmode(_fileno(stdout), 0x00020000);
    
    ptrF = fgets(strF, 20, fin);
    *(ptrF + strlen(ptrF) - 1) = L'\0';

    ptr1 = fgetws(str1, 20, stdin);
    *(ptr1 + wcslen(ptr1) - 1) = '\0';

    mbstowcs(strC, strF, 20); 
    ptrC = strC;

    if (wcslen(ptr1) < wcslen(ptrC)) {
        wcscat(res, ptrC);
        wcscat(res, ptr1);
    }
    else {
        wcscat(res, ptr1);
        wcscat(res, ptrC);
    }
    
    fwprintf(fout, L"%s", res);
    wprintf(L"%s", res);
    
    fclose(fin);
    fclose(fout);
    return 0;
}