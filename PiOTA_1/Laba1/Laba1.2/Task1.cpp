//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.2 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//������������� � �������� ����
//09.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long ll;

int main()
{
	ll a, k, m;
	(void)scanf("%d %d %d", &a, &k, &m);
	ll msK = 1 << k;
	ll msM = 1 << m;
	a ^= msK;
	a &= ~msM;
	printf("%d", a);
	return 0;
}