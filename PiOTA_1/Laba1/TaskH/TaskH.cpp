//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.1 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//������� H
//08.10.2023
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;
int main() {
	unsigned int a, h, m;
	cin >> a;
	h = 9 + ((45 * a) + (a/2)*5 + ((a+1)/2 - 1)*15) / 60;
	m = ((45 * a) + (a / 2) * 5 + ((a + 1)/ 2 - 1)*15) % 60;
	cout << h << ' ' << m;
}