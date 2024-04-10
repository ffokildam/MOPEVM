#include <stdio.h>

int main() {
    char st[256];
    gets(st);
    char* pt1 = st;
    char* pt2 = st;
    while (*pt2 != ' ') pt2++;
    *pt2 = '\0';
    pt2++;
    printf("%s %s", pt2, pt1);
}