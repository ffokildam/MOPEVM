//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskBoard1
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int m, n, x, y;
	cin >> m >> n;
	cin >> x >> y;
	if (x > 1) cout << x - 1 << ' ' << y << endl;
	if (y > n) cout << x + 1 << ' ' << y << endl;
	if (y>1) cout << x << ' ' << y - 1 << endl;
	if (y > m) cout << x << ' ' << y + 1 << endl;
	return 0;
}