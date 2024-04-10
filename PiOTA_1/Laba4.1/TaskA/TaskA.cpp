//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.1 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//14.11.2023
#include <iostream>

using namespace std;

/*Функция isalive считает расстояния между объектами Суслик/Норка, Собака/Норка с помощью уравнения расстояния между 2 точками.
На вход получает параметры:
dX - x координата собаки
dY - y координата собаки
gX - x координата суслика
gY - y координата суслика
nX - x координата норки
nY - y координата норки
После подсчета расстояний, сравнивает их. Если расстояние собаки более чем в 4 раза(не 2 т.к. не использую sqrt в формуле)больше или равно расстоянию суслика, то isalive возвращает 1, иначе 0
*/
bool isalive(int, int, int, int, int, int);

int main()
{
	int gopherX, gopherY;	
	int dogX, dogY;
	cin >> gopherX >> gopherY;
	cin >> dogX >> dogY;
	int n;
	bool stop = 0;
	bool found = 0;
	cin >> n;
	int norX, norY;
	for (int i = 0; i < n && stop == 0; i++) {
		cin >> norX >> norY;
		found = isalive(dogX,dogY,gopherX,gopherY,norX,norY);
		if (found == 1) {
			stop = 1;
			cout << i + 1;
		}
	}
	if (found == 0) cout << "NO";
}

bool isalive(int dX, int dY, int gX, int gY, int nX, int nY) {
	long long int distG = (gX - nX) * (gX - nX) + (gY - nY) * (gY - nY);
	long long int distD = (dX - nX) * (dX - nX) + (dY - nY) * (dY - nY);
	if (distD >= distG * 4) return 1;
	else return 0;
}