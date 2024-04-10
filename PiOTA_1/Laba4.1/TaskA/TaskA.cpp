//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����4.1 - ������������, ������������ �������
//����1-6, ��������� ��������� ���������
//TaskA
//14.11.2023
#include <iostream>

using namespace std;

/*������� isalive ������� ���������� ����� ��������� ������/�����, ������/����� � ������� ��������� ���������� ����� 2 �������.
�� ���� �������� ���������:
dX - x ���������� ������
dY - y ���������� ������
gX - x ���������� �������
gY - y ���������� �������
nX - x ���������� �����
nY - y ���������� �����
����� �������� ����������, ���������� ��. ���� ���������� ������ ����� ��� � 4 ����(�� 2 �.�. �� ��������� sqrt � �������)������ ��� ����� ���������� �������, �� isalive ���������� 1, ����� 0
*/
bool isalive(int, int, int, int, int, int);

int main()
{
	int gopherX, gopherY;	
	int dogX, dogY;
	cin >> gopherX >> gopherY;
	cin >> dogX >> dogY;
	int n;
	bool stop = 0;
	bool found = 0;
	cin >> n;
	int norX, norY;
	for (int i = 0; i < n && stop == 0; i++) {
		cin >> norX >> norY;
		found = isalive(dogX,dogY,gopherX,gopherY,norX,norY);
		if (found == 1) {
			stop = 1;
			cout << i + 1;
		}
	}
	if (found == 0) cout << "NO";
}

bool isalive(int dX, int dY, int gX, int gY, int nX, int nY) {
	long long int distG = (gX - nX) * (gX - nX) + (gY - nY) * (gY - nY);
	long long int distD = (dX - nX) * (dX - nX) + (dY - nY) * (dY - nY);
	if (distD >= distG * 4) return 1;
	else return 0;
}