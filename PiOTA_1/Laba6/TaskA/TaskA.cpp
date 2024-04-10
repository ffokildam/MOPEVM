//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.1 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//17.12.2023
#include <iostream>

using namespace std;

/* Функция сравения элементов массива, необходимая для работы библиотечной функции qsort
* На вход получает параметры:
* x1 - указатель на 1 используемый элемент массива
* x2 - указатель на 2 используемый элемент массива
* В зависимости от результата функция возвращает разные значения
* Если x1<x2, то возвращаемый результат <0, если x1>x2, то возвращаемый результат >0, если x1-x2, то возвращемый результат 0.
*/
int cmp(const void*, const  void*);

int main(){
    int n;
    cin>>n;
    int count1=0,count2=0,count3=0;
    int *mass1 = (int*)calloc(n, sizeof(int));
    int *mass2 = (int*)calloc(n, sizeof(int));
    int *massFOUND = (int*)calloc(n, sizeof(int));
    char tmp = NULL;
    for(int i = 0; tmp != '\n'; i++) 
    {
        scanf("%d%c", &mass1[i],&tmp);
        count1++;
    }
    tmp = NULL;
    for(int i = 0; tmp != '\n'; i++) 
    {
        scanf("%d%c", &mass2[i],&tmp);
        count2++;
    }
    qsort(mass1, count1, sizeof(int), cmp);       
    qsort(mass2, count2, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
    {
        int pattern = mass1[i];
        int left=0, right=count2;
        int m, flag=0;
        while ((left < right) && (!flag))
        {
            m = (left + right) / 2;
            if (mass2[m] == pattern)
                flag = 1;
            else if (mass2[m] < pattern)
                left = m + 1;
                else
                    right = m;

        }
        if (flag){
            bool exist=0;
            for (int i = 0; i < count3; i++)
            {
                if(pattern == massFOUND[i]){
                    exist = 1;
                }
            }
            if(!exist){
                massFOUND[count3]=pattern;
                count3++;
            }
        }
    }
    for (int i = 0; i < count3; i++)
    {
        cout<<massFOUND[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= n; ++i) {
        bool found = false;

        bool brk=0;
        for (int j = 0; j < count1 && !brk; ++j) {
            if (mass1[j] == i) {
                found = true;
                brk=1;
            }
        }
        brk=0;
        for (int k = 0; k < count2; ++k) {
            if (mass2[k] == i) {
                found = true;
                brk=1;
            }
        }

        if (!found) {
            cout << i << " ";
        }
    }
    return 0;



}

int cmp(const void* x1, const void* x2) {

    return (*(int*)x1 - *(int*)x2);

}