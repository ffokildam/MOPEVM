//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskBoard4
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int x, k, countNS = 0,countPOL;
	cin >> x;
	for (countPOL = 0; x; x--) {
		cin >> k;
		if (k != -1) countPOL += k;
		else {
			if (countPOL == 0) countNS++;
			else countPOL--;
		}
	}
	cout << countNS << endl;
}