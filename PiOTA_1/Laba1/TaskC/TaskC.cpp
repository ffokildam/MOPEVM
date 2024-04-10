//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.1 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Задание C
//03.10.2023
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll a, a1, a2, res1, res2,sum1,sum2;
	cin >> a;
	a1 = a / 1000;
	a2 = a % 1000;
	res1 = a1 % 10;
	a1 /= 10;
	res1 += a1 % 10;
	a1 /= 10;
	res1 += a1 % 10;
	res2 = a2 % 10;
	a2 /= 10;
	res2 += a2 % 10;
	a2 /= 10;
	res2 += a2 % 10;
	(res1 == res2) ? cout << "YES" : cout << "NO";
}

