//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskH
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	int num, count, mid, rest;
	cin >> num >> count;
	mid = num / count;
	rest = num % count;
	for (; count; count--) {
		if (count == rest) {
			cout << mid + 1 << ' ';
			rest--;
		}
		else cout << mid<<' ';
	}
}