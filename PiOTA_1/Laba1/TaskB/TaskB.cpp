//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.1 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//������� B
//03.10.2023
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int a, b, c, res;
	cin >> a >> b >> c;
	ll f;
	f = (a + b + 1) / b;
	res =  (a + c - 1) - b * f;
	cout << res;
}

