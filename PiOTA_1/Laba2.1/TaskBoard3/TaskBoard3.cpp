//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskBoard3
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int x,x1=0,temp;
	cin >> x;
	for(x;x>0;x/=10)
	if (x == x1)
		cout << "Yes";
	else
		cout << "No";
}