//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//Task�
//16.10.2023
#include <iostream>

using namespace std;

int main()
{
	int n, k, count0 = 0, countPOL = 0, countOTR=0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> k;
		if (k == 0) count0++;
		if (k > 0) countPOL++;
		if (k < 0) countOTR++;
	}
	cout << count0 << ' ' << countPOL << ' ' << countOTR << endl;
}