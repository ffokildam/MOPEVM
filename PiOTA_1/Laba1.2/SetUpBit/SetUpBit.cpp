//���, �����, ��� ���
//���������������� � ������ ������ ����������
//���� 1.2 - ���������������� �������� ����������
//����1-6, ��������� ��������� ���������
//���������� ���
//09.10.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long ll;

int main() {
    ll a, k;
    scanf("%lld %lld", &a, &k);
    ll mask = 1;
    mask = mask << k;
    a = a | mask;
    printf("%lld", a);

    return 0;
}



