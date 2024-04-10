//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����4.1 - ������������, ������������ �������
//����1-6, ��������� ��������� ���������
//TaskF
//14.11.2023
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* ������������ Queen ��������� ��� ������, ����������� ��� ���� �����
* �� ���� �������� ���������:
* a - ���������� X �����
* b - ���������� Y �����
* array - ��������� �� ������ chess, �������������� ����� ��������� ����
* �������� �������� ������� ����������, ��� ��� ������ �������� ������� chess
*/
void Queen(int , int , int(&)[8][8]);

/* ������������ Rook ��������� ��� ������, ����������� ��� ���� �����
* �� ���� �������� ���������:
* a - ���������� X �����
* b - ���������� Y �����
* array - ��������� �� ������ chess, �������������� ����� ��������� ����
* �������� �������� ������� ����������, ��� ��� ������ �������� ������� chess
*/
void Rook(int , int , int(&)[8][8]);

/* ������������ Knight ��������� ��� ������, ����������� ��� ���� ����
* �� ���� �������� ���������:
* a - ���������� X ����
* b - ���������� Y ����
* array - ��������� �� ������ chess, �������������� ����� ��������� ����
* �������� �������� ������� ����������, ��� ��� ������ �������� ������� chess
*/
void Knight(int , int , int(&)[8][8]);

void (*allpos[3])(int , int , int(&)[8][8]) = { Queen, Rook, Knight };

int main() {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    int chess[8][8] = { 0 };
    int queenX = s1[0] - 65;
    int queenY = s1[1] - 49;
    int rookX = s2[0] - 65;
    int rookY = s2[1] - 49;
    int knightX = s3[0] - 65;
    int knightY = s3[1] - 49;
    int sum = 0;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++) {
            (*allpos[0])(queenX, queenY,chess);
            (*allpos[1])(rookX, rookY, chess);
            (*allpos[2])(knightX, knightY, chess);
        }
    chess[queenY][queenX] = 0;
    chess[rookY][rookX] = 0;
    chess[knightY][knightX] = 0;
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (chess[i][j] == 1) sum++;
    cout << sum;
}

void Queen(int a, int b, int(&array)[8][8]) {
    for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) if ((abs(a - y) == abs(b - x)) || a == y || b == x) array[x][y] = 1;
}

void Rook(int a, int b, int(&array)[8][8]) {
    for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) if (a == y || b == x) array[x][y] = 1;
}

void Knight(int a, int b, int(&array)[8][8]){
    for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) if ((abs(a - y) == 1 && abs(b - x) == 2) || (abs(a - y) == 2 && abs(b - x) == 1)) array[x][y] = 1;
}