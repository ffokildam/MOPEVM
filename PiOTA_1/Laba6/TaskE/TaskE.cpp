//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.2 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskE
//20.12.2023
#include <iostream>

using namespace std;

union AdrUnion {
    struct {
        unsigned char num1;
        unsigned char num2;
        unsigned char num3;
        unsigned char num4;
    } address;
    unsigned int value;
};

int main() {
    int n, m;
    scanf("%d", &n);

    AdrUnion masks[n];
    for (int i = 0; i < n; i++) {
        char maskStr[16];
        scanf("%hhu.%hhu.%hhu.%hhu", &masks[i].address.num1, &masks[i].address.num2, &masks[i].address.num3, &masks[i].address.num4);
        masks[i].value = masks[i].value;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        AdrUnion ip1, ip2;
        char ip1Str[16], ip2Str[16];
        scanf("%hhu.%hhu.%hhu.%hhu %hhu.%hhu.%hhu.%hhu", &ip1.address.num1, &ip1.address.num2, &ip1.address.num3, &ip1.address.num4,&ip2.address.num1, &ip2.address.num2, &ip2.address.num3, &ip2.address.num4);

        int count = 0;
        for (int j = 0; j < n; ++j) {
            if ((ip1.value & masks[j].value) == (ip2.value & masks[j].value)) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
