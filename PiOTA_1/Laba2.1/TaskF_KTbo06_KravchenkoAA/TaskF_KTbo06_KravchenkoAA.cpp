//���, �����, ��� ���
//���������������� � ������ ������ ����������
//����2.1 - �������� ���������
//����1-6, ��������� ��������� ���������
//TaskF
//17.10.2023
#include <iostream>

using namespace std;

int main()
{
	int countPPL, V, S, pos, maxAge = 0;
	cin >> countPPL;
	for (int i = 0; i < countPPL; i++) {
		cin >> V >> S;
		if (S == 1) {
			if (V > maxAge) {
				maxAge = V;
				pos = i+1;
			}
		}
	}
	if (maxAge == 0) cout << -1;
	else cout << pos;
}