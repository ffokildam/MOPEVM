//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	if (k < n * m && (k % n == 0 || k % m == 0))
		cout << "YES";
	else
		cout << "NO";
}