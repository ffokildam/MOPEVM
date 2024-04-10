//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба4.1 - Подпрограммы, библиотечные функции
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//17.11.2023
#include <iostream>
#include <string>

using namespace std;

/* Функция инициализирует массив проверки - заполняет массив checkContainer числами от 1 до n^2
   На вход получает: a - указатель на массив checkContainer, n - переменная n из функции main
   Функция изменияет значения массива checkContainer */
void initializeCeCont(int(&a)[101], int);

/* Функция checkColumn проверяет каждый столбец на соответсвие условию судоку
* На вход получает параметры
* a - указатель на массив sudoku
* n - "степень" судоку
* b - указатель на массив на массив b, являющийся "коллекцией" чисел для степени данного судоку
* Если все столбцы проходят условие - возвращает 1, иначе - 0
*/
bool checkColumn(int(&a)[101][101], int, int(&b)[101]);

/* Функция checkLine проверяет каждую строку на соответсвие условию судоку
* На вход получает параметры
* a - указатель на массив sudoku
* n - "степень" судоку
* b - указатель на массив на массив checkContainer, являющийся "коллекцией" чисел для степени данного судоку
* Если все строки проходят условие - возвращает 1, иначе - 0
*/
bool checkLine(int(&a)[101][101], int, int(&b)[101]);

/* Функция checkColumn проверяет каждый квадрат на соответсвие условию судоку
* На вход получает параметры
* a - указатель на массив sudoku
* n - "степень" судоку
* b - указатель на массив на массив b, являющийся "коллекцией" чисел для степени данного судоку
* Если все квадраты проходят условие - возвращает 1, иначе - 0
*/
bool checkSq(int(&a)[101][101], int, int(&b)[101]);


int main() {
    int n;
    int sudoku[101][101];
    cin >> n;
    int checkContainer[101];
    int res1 = 0;
    for (int i = 0; i < n * n; i++) for (int j = 0; j < n * n; j++) cin >> sudoku[i][j];
    initializeCeCont(checkContainer, n);
    res1 = checkColumn(sudoku, n, checkContainer);
    int res2 = checkLine(sudoku, n, checkContainer);
    int res3 = checkSq(sudoku, n, checkContainer);
    if (res1 && res2 && res3) cout << "Correct";
    else cout << "Incorrect";
}

void initializeCeCont(int(&a)[101], int n) {
    for (int i = 0; i < n * n; i++) a[i] = i + 1;
}

bool checkColumn(int(&a)[101][101], int n, int(&b)[101]) {
    int sum = 0;
    for (int i = 0; i < n * n; i++)
    {
        initializeCeCont(b, n);
        for (int j = 0; j < n * n; j++) {
            int stop = 0;
            for (int k = 0; k < n * n && stop == 0; k++)
            {
                if (a[j][i] == b[k]) {
                    b[k] = 0;
                    stop = 1;
                    sum++;
                }
            }
        }
    }
    if (sum == n * n * n * n) return 1;
    else return 0;
}

bool checkLine(int(&a)[101][101], int n, int(&b)[101]) {
    int sum = 0;
    for (int i = 0; i < n * n; i++)
    {
        initializeCeCont(b, n);
        for (int j = 0; j < n * n; j++) {
            int stop = 0;
            for (int k = 0; k < n * n && stop == 0; k++)
            {
                if (a[i][j] == b[k]) {
                    b[k] = 0;
                    stop = 1;
                    sum++;
                }
            }
        }
    }
    if (sum == n * n * n * n) return 1;
    else return 0;
}

bool checkSq(int(&a)[101][101], int n, int(&b)[101]) {
    int sum = 0;
    for (int i = 0; i < n * n; i += n) {
        for (int j = 0; j < n * n; j += n)
        {
            initializeCeCont(b, n);
            for (int m = 0; m < n; m++) for (int l = 0; l < n; l++) {
                int stop = 0;
                for (int k = 0; k < n * n && stop == 0; k++)
                {
                    if (a[i + m][j + l] == b[k]) {
                        b[k] = 0;
                        stop = 1;
                        sum++;
                    }
                }
            }
        }
    }
    if (sum == n * n * n * n) return 1;
    else return 0;
}