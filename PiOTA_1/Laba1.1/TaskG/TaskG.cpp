//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба 1.1 - программирование линейных алгоритмов
//КТбо1-6, Кравченко Александр Андреевич
//Задание G
//08.10.2023
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef double dd;

int main()
{
	ll x1, x2, x3, y1, y2, y3, xc, yc;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cin >> xc >> yc;
	dd a = y2 - y1, b = x2 - x1;
	dd dis1 = fabs(1.0 * (a * xc - b * yc + x2 * y1 - y2 * x1));
	dis1 /= sqrt(a * a + b * b);
	a = y3 - y1;
	b = x3 - x1;
	dd dis2 = fabs(1.0 * (a * xc - b * yc + x3 * y1 - y3 * x1));
	dis2 /= sqrt(a * a + b * b);
	a = y2 - y3;
	b = x2 - x3;
	dd dis3 = fabs(1.0 * (a * xc - b * yc + x2 * y3 - y2 * x3));
	dis3 /= sqrt(a * a + b * b);
	(dis1 < dis2) ? dis1 = dis1 : dis1 = dis2;
	(dis1 < dis3) ? dis1 = dis1 : dis1 = dis3;
	printf("%.10f", dis1);
}