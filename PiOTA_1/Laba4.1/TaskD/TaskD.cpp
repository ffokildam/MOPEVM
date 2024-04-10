//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����4.1 - ������������, ������������ �������
//����1-6, ��������� ��������� ���������
//TaskD
//17.11.2023
#include <iostream>
#include <string>

using namespace std;

/* ������� �������������� ������ �������� - ��������� ������ checkContainer ������� �� 1 �� n^2
   �� ���� ��������: a - ��������� �� ������ checkContainer, n - ���������� n �� ������� main
   ������� ��������� �������� ������� checkContainer */
void initializeCeCont(int(&a)[101], int);

/* ������� checkColumn ��������� ������ ������� �� ����������� ������� ������
* �� ���� �������� ���������
* a - ��������� �� ������ sudoku
* n - "�������" ������
* b - ��������� �� ������ �� ������ b, ���������� "����������" ����� ��� ������� ������� ������
* ���� ��� ������� �������� ������� - ���������� 1, ����� - 0
*/
bool checkColumn(int(&a)[101][101], int, int(&b)[101]);

/* ������� checkLine ��������� ������ ������ �� ����������� ������� ������
* �� ���� �������� ���������
* a - ��������� �� ������ sudoku
* n - "�������" ������
* b - ��������� �� ������ �� ������ checkContainer, ���������� "����������" ����� ��� ������� ������� ������
* ���� ��� ������ �������� ������� - ���������� 1, ����� - 0
*/
bool checkLine(int(&a)[101][101], int, int(&b)[101]);

/* ������� checkColumn ��������� ������ ������� �� ����������� ������� ������
* �� ���� �������� ���������
* a - ��������� �� ������ sudoku
* n - "�������" ������
* b - ��������� �� ������ �� ������ b, ���������� "����������" ����� ��� ������� ������� ������
* ���� ��� �������� �������� ������� - ���������� 1, ����� - 0
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