//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����3.1 - �������, ���������, ������
//����1-6, ��������� ��������� ���������
//TaskK
//08.11.2023
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main()
{
    char s[251];
    char* pt1 = s;
    int n = 0,len=0;
    (void)scanf("%s", s);
    for (; *pt1 != '\0'; pt1++)len++;
    pt1 = s;
    for (int i = 0; i < len - 4; i++) {
        if ((*pt1 == '>') && (*(pt1 + 1) == '>') && (*(pt1 + 2) == '-') && (*(pt1 + 3) == '-') && (*(pt1 + 4) == '>')) n++;
        else if ((*(pt1) == '<') && (*(pt1 + 1) == '-') && (*(pt1 + 2) == '-') && (*(pt1 + 3) == '<') && (*(pt1 + 4) == '<')) n++;
        pt1++;
    }
    printf("%d", n);
}