#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100], s1[100] = "";

    scanf("%s", s);

    if (s[0] == '_' || s[strlen(s) - 1] == '_') {
        printf("Error!");
        return 0;
    }

    if (strstr(s, "__") != NULL) {
        printf("Error!");
        return 0;
    }

    int p = 0;

    for (int i = 0; i < strlen(s); i++)
        if (isupper(s[i]) && i > 0) {
            p++;
            break;
        }

    int ss = (int)(strchr(s, '_') - s);

    if (p > 0 && ss > 0) {
        printf("Error!");
        return 0;
    }

    if (isupper(s[0])) {
        printf("Error!");
        return 0;
    }

    if (p > 0) {
        int idx = 0;

        for (int i = 0; i < strlen(s); i++) {
            if (islower(s[i])) {
                s1[idx] = s[i];
                idx++;
            }
            else if (isupper(s[i])) {
                s1[idx] = '_';
                idx++;
                s1[idx] = tolower(s[i]);
                idx++;
            }
        }

        s1[idx] = '\0';

        printf("%s", s1);
        return 0;
    }
    else {
        if (strchr(s, '_') != NULL) { // C++
            int idx = 0;

            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == '_') {
                    s1[idx] = toupper(s[i + 1]);
                    idx++;
                    i++;
                }
                else {
                    s1[idx] = s[i];
                    idx++;
                }
            }

            s1[idx] = '\0';

            printf("%s", s1);
            return 0;
        }
    }
}
