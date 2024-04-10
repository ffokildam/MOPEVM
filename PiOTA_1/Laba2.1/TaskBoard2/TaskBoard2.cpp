//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskBoard2
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x > 12)
		cout << "Error";
	if (x > 11 && x < 3)
		cout << "Winter";
	if (x > 2 && x < 6)
		cout << "Spring";
	if (x > 5 && x < 9)
		cout << "Summer";
	if (x > 8 && x < 12)
		cout << "Autumn";
	return 0;
}