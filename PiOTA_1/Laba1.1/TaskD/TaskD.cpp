//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.1 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//������� E
//03.10.2023
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ll c, h, o, min1;
	cin >> c >> h >> o;
	min1 = (c / 2 < h / 6) ? c / 2 : h / 6;
	(min1 < o) ? cout << min1 : cout << o;
}