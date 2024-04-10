//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	long int a, b, c, d, x;
	cin >> a >> b >> c >> d;
	for (x = 1000; x>-1; x--) {
		if (a * x * x * x + b * x * x + c * x + d == 0) cout <<x<<' ';
	}
}