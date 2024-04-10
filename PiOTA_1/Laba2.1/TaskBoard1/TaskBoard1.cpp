//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskBoard1
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int m, n, x, y;
	cin >> m >> n;
	cin >> x >> y;
	if (x > 1) cout << x - 1 << ' ' << y << endl;
	if (y > n) cout << x + 1 << ' ' << y << endl;
	if (y>1) cout << x << ' ' << y - 1 << endl;
	if (y > m) cout << x << ' ' << y + 1 << endl;
	return 0;
}