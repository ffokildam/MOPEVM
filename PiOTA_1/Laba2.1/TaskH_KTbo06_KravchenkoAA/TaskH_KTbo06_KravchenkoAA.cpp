//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskH
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	int num, count, mid, rest;
	cin >> num >> count;
	mid = num / count;
	rest = num % count;
	for (; count; count--) {
		if (count == rest) {
			cout << mid + 1 << ' ';
			rest--;
		}
		else cout << mid<<' ';
	}
}