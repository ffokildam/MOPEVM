//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба6.2 - Структуры данных. Динамическая память
//КТбо1-6, Кравченко Александр Андреевич
//TaskF
//21.12.2023
/*
Тестовые входные данные: 0x11223344, 0x55667788, 0x99AABBCC (есть в массиве вхлдных данных в программе)
Результат: 
Pixel 1: Brightness = 47.85
Pixel 2: Brightness = 30.85
Pixel 3: Brightness = 13.85
Pixel 4: Brightness = 115.86
*/
#include <stdio.h>

union RGBPixel {
    unsigned int word;
    struct {
        unsigned char blue;
        unsigned char green;
        unsigned char red;
        unsigned char pad;
    } bytes;
};

int main() {
    unsigned int Bytes[] = { 0x11223344, 0x55667788, 0x99AABBCC };

    int numPixels = sizeof(Bytes) * 8 / 24;

    for (int i = 0; i < numPixels; ++i) {
        union RGBPixel pixel;
        pixel.word = Bytes[i / 3];
        pixel.word >>= (i % 3) * 8;
        float brightness = 0.299 * pixel.bytes.red + 0.587 * pixel.bytes.green + 0.114 * pixel.bytes.blue;
        printf("Pixel %d: Brightness = %.2f\n", i + 1, brightness);
    }
    return 0;
}
