//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба2.1 - условные операторы
//КТбо1-6, Кравченко Александр Андреевич
//TaskE
//17.10.2023
#include <iostream>

using namespace std;

int main() {
	int count, n;
	long long res=0;
	cin >> count;
	for (int streak = 3;count;count--) {
		cin >> n;
		if (n) {
			res += streak;
			streak++;
		}
		else {
			(streak > 6) ? streak -= 3 : streak = 3;
		}
	}
	cout << res << endl;
}