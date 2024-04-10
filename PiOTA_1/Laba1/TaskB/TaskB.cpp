//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.1 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Задание B
//03.10.2023
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int a, b, c, res;
	cin >> a >> b >> c;
	ll f;
	f = (a + b + 1) / b;
	res =  (a + c - 1) - b * f;
	cout << res;
}

