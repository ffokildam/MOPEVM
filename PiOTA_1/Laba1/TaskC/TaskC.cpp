//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.1 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//������� C
//03.10.2023
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll a, a1, a2, res1, res2,sum1,sum2;
	cin >> a;
	a1 = a / 1000;
	a2 = a % 1000;
	res1 = a1 % 10;
	a1 /= 10;
	res1 += a1 % 10;
	a1 /= 10;
	res1 += a1 % 10;
	res2 = a2 % 10;
	a2 /= 10;
	res2 += a2 % 10;
	a2 /= 10;
	res2 += a2 % 10;
	(res1 == res2) ? cout << "YES" : cout << "NO";
}

