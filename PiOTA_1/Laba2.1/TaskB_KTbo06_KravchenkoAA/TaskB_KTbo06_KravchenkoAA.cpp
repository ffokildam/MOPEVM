//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int a,b;
	cin >> a;
	b = a % 10;
	switch (a)
	{
	case 11:
		cout << a << " korov";
		b = 19;
		break;
	case 12:
		cout << a << " korov";
		b = 19;
		break;
	case 13:
		cout << a << " korov";
		b = 19;
		break;
	case 14:
		cout << a << " korov";
		b = 19;
		break;
	
	}
	switch (b) {
		case 1:
			cout << a << " korova";
			break;
		case 2:
		case 3:
		case 4:
			cout << a << " korovy";
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0:
			cout << a << " korov";
			break;	
	}
}