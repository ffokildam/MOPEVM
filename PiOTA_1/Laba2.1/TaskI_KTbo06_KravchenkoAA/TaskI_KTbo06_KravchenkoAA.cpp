//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskI
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0 || i == 1) {
			if(i==n) cout << "I hate it";
			else cout << "I hate that ";
		}
		else {
			if (i == n) cout << "I love it";
			else cout << "I love that ";
		}
	}
}