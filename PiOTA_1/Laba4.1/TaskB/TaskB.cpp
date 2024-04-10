//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.1 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskB
//14.11.2023
#include <iostream>
#include <string>

using namespace std;

/* Подпрограмма buttonPress эмулирует нажатие кнопки лифта, тем самым изменяя текущий этаж
* На вход получает параметры:
* liftbutton - какая кнопка лифта нажата
* maxFloor - максимальный полученный "виртуальный" этаж
* floor - текущий "виртуальный" этаж
* minFloor - минимальный полученный "виртуальный" этаж
* res - переменная результата, считает разницу между min/max, тем самым находя кол-во этажей
* 
* Каждый из параметров - указатель, следовательно подпрограмма изменяет исходные значения параметров
*/
void buttonPress(int,int *, int *,int*,int*);

int main() {
	string allPressed;
	int press;
	int floor = 0;
	int maxFloor = 0;
	int minFloor = 0;
	int res;
	cin >> allPressed;
	for (int i = 0; i < allPressed.length(); i++) {
		press = allPressed[i]-48;
		buttonPress(press,&maxFloor,&floor,&minFloor,&res);
	}
	cout << res;
}
void  buttonPress(int liftbutton, int *maxFloor,int* floor, int* minFloor,int*res) {
	if (liftbutton == 1) *floor += 1;
	if (liftbutton == 2) *floor -= 1;
	if (*floor > *maxFloor) *maxFloor = *floor;
	if (*floor < *minFloor) *minFloor = *floor;
	*res = *maxFloor - *minFloor + 1;
}