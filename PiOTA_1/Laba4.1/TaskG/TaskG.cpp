//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.1 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//14.11.2023
#include <iostream>
using namespace std;

/* Функция Iter считает каждую "итерацию" игры, в зависимости от текущего шага прибавляет число к 1 или ко 2 игроку
* На вход получает параметры:
* arrleft - указатель на крайний левый элемент массива
* arrright - указатель на крайний правый элемент массива
* right - правая граница массива
* left - левая граница массива
* side - указывает на текущий ход, если 0 - 1 игрок, если 1 - 2 игрок
* player1 - сумма очков первого игрока
* player2 - сумма очков втрого игрока
*
* Каждый из параметров - указатель, следовательно подпрограмма изменяет исходные значения параметров
*/
void Iter(int*, int*, int*, int*, bool*, int*, int*);

int main() {
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int player1 = 0;
    int player2 = 0;
    int left = 0;
    int right = n - 1;
    bool side = 0;
    while (right>=left) Iter(&arr[left], &arr[right], &left, &right, &side, &player1, &player2);
    cout << player1 << ":" << player2;
}

void Iter(int* arrleft, int* arrright, int* left, int* right, bool* side, int* player1, int* player2) {
    if ((*arrleft >= *arrright) && *side == 0) {
        *player1 += *arrleft;
        *left+=1;
        *side = 1;
    }
    else if ((*arrleft >= *arrright) && *side == 1) {
        *player2 += *arrleft;
        *left += 1;
        *side = 0;
    }
    else if ((*arrleft < *arrright) && *side == 0) {
        *player1 += *arrright;
        *right -= 1;
        *side = 1;
    }
    else if ((*arrleft < *arrright) && *side == 1) {
        *player2 += *arrright;
        *right-=1;
        *side = 0;
    }
}