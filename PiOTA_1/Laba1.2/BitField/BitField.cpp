//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.2 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//��������� �������� ����
//10.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	unsigned int x, N, K;
	(void)scanf("%d %d %d", &x, &N, &K);
	unsigned int msk = ((1 << (K - N + 1)) - 1) << N;
	x = (x & msk) >> N;
	printf("%d", x);
	return 0;
}