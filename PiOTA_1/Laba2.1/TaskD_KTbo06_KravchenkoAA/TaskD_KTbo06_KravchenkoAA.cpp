//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	int a1, a2, a3, b1, b2, b3, res;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	if (a1 < a2) {
		res = a1; 
		a1 = a2; 
		a2 = res;
	}
	if (a2 < a3) {
		res = a2; 
		a2 = a3; 
		a3 = res;
	}
	if (a1 < a2) {
		res = a1; 
		a1 = a2; 
		a2 = res;
	}
	if (b1 < b2) {
		res = b1; 
		b1 = b2; 
		b2 = res;
	}
	if (b2 < b3) {
		res = b2; 
		b2 = b3; 
		b3 = res;
	}
	if (b1 < b2) {
		res = b1; 
		b1 = b2; 
		b2 = res;
	}
	cout << a1 * b1 + a2 * b2 + a3 * b3;
}
