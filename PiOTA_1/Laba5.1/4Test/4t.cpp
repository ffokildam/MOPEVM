#include <stdio.h>
#define CIT(X) #X;
#define CNC(X,Y,Z) X##Y##Z
#define VAL 641221
int main(void) {
	int i = CNC(64, 12, 21);
	int j = i + VAL;
	char* s = CIT(i);

	printf_s("%d%s",j,s );
}