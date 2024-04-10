//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����4.2 - ������������, ������������ �������
//����1-6, ��������� ��������� ���������
//TaskH
//22.11.2023
#include <iostream>
#include <cmath>

using namespace std;

/*������������ fMD ��������� ��������� ������� ���� ��������� ��������� ���������� ������.
* ������� ������ 2 ����������� ������, ��� ����� ������������� ������� ���������� ������ ���� � ���� �� ���� ���, � ����� ���������� ������� �� �������.
* �� ���� �������� ���������:
* weights - ������ �� ������ ���� ���� ������ � ����.
* i - ������� ����� � �������
* sum1 - ����� ������ ����
* sum2 - ����� ������ ����
*/
int fMD(const int(&)[18], int, int, int, int);

int main() {
    int N;
    cin >> N;
    int weights[18];
    for (int i = 0; i < N; i++) cin >> weights[i];
    int minDifference = fMD(weights, 0, 0, 0,N);
    cout << minDifference << endl;
}
int fMD(const int(&weights)[18], int i, int sum1, int sum2, int N) {
    if (i == N) return abs(sum1 - sum2);
    return min(fMD(weights, i + 1, sum1 + weights[i], sum2, N), fMD(weights, i + 1, sum1, sum2 + weights[i], N));
}