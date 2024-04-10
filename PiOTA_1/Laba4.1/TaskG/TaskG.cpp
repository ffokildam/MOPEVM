//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����4.1 - ������������, ������������ �������
//����1-6, ��������� ��������� ���������
//TaskG
//14.11.2023
#include <iostream>
using namespace std;

/* ������� Iter ������� ������ "��������" ����, � ����������� �� �������� ���� ���������� ����� � 1 ��� �� 2 ������
* �� ���� �������� ���������:
* arrleft - ��������� �� ������� ����� ������� �������
* arrright - ��������� �� ������� ������ ������� �������
* right - ������ ������� �������
* left - ����� ������� �������
* side - ��������� �� ������� ���, ���� 0 - 1 �����, ���� 1 - 2 �����
* player1 - ����� ����� ������� ������
* player2 - ����� ����� ������ ������
*
* ������ �� ���������� - ���������, ������������� ������������ �������� �������� �������� ����������
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