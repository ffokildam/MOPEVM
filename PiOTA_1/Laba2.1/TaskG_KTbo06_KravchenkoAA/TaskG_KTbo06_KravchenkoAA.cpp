//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskG
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	long int a, b, c, d, x;
	cin >> a >> b >> c >> d;
	for (x = 1000; x>-1; x--) {
		if (a * x * x * x + b * x * x + c * x + d == 0) cout <<x<<' ';
	}
}