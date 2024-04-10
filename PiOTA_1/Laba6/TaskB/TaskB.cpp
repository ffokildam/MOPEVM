//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.1 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//12.12.2023

#include <iostream>
#include <string>

using namespace std;

struct Student{
    char Name[100];
    char Surname[100];
    double math;
    double phy;
    double inf;
    double avg;
};

int main(){

    Student Students[100];
    int n;
    double bMark;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>Students[i].Name>>Students[i].Surname>>Students[i].math>>Students[i].phy>>Students[i].inf;
        Students[i].avg = (Students[i].inf + Students[i].math + Students[i].phy)/3;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (Students[j].avg > Students[i].avg) {
                Student temp = Students[j];
                Students[j] = Students[i];
                Students[i] = temp;
            }
        }
    }
    bMark = Students[0].avg;
    for (int i = 0; Students[i].avg==bMark; i++)
    {
        cout<<Students[i].Name<<" "<<Students[i].Surname<<endl;
    }
}