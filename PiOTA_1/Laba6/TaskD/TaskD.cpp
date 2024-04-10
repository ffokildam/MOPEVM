//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.1 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//14.12.2023

#include <iostream>
#include <cstring>

using namespace std;

struct P_File{
    char Surname[21];
    char Name[21];
    char Class[4];
    char BirthDate[9];
};

/*
Функция get_num получает указатель на char из компаратора, который в свою очередь указывает на элемент Class из структуры P_File
Возвращает число - цифру класса, извлеченную из строки.
*/
int get_num(char*);

/* Функция сравения элементов массива, необходимая для работы библиотечной функции qsort, на вход получает два указателя на элементы массива P_File
Сначала сравнивает цифры класса, затем, если они равны, сравнивает буквы, если буквы равны - сравнивает фамилии.
Возвращает результаты сравнения элементов.
*/
int compP_Files(const void*, const void*);

int main(){
    int n;
    cin>>n;

    P_File *Files = (P_File*)calloc(n, sizeof(P_File));

    for (int i = 0; i < n; i++)
    {
        cin>>Files[i].Surname;
        cin>>Files[i].Name;
        cin>>Files[i].Class;
        cin>>Files[i].BirthDate;
    }
    
    qsort(Files, n, sizeof(P_File), compP_Files);

    for (int i = 0; i < n; i++) {
       cout<<Files[i].Class<<' '<<Files[i].Surname<<' '<<Files[i].Name<<' '<<Files[i].BirthDate<<endl;
    }

    free(Files);
    return 0;

}

int get_num(char* str) {
    int num = 0;
    while (*str >= 48 && *str <= 57) {
        num = num * 10 + (*str - 48);
        str++;
    }
    return num;
}

int compP_Files(const void* a, const void* b) {
    P_File* fileA = (P_File*)a;
    P_File* fileB = (P_File*)b;

    int numA = get_num(fileA->Class);
    int numB = get_num(fileB->Class);

    if (numA != numB) {
        return numA - numB;
    }

    int letterComp = strcmp(fileA->Class + strlen(fileA->Class) - 1, fileB->Class + strlen(fileB->Class) - 1);

    if (letterComp != 0) {
        return letterComp;
    }

    return strcmp(fileA->Surname, fileB->Surname);
}