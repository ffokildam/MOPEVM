//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskBoard5
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	char c;
	int n, m;
	int flagBW = 1;
	cin >> n >> m;
	for (size_t i = 0; i < n*m; i++)
	{
		cin >> c;
		if ((c != 'B') && (c != 'W') && (c != 'G')) flagBW = 0;
	}
	if (flagBW == 1) cout << "#Black&White";
	else cout << "#Color";
	
}