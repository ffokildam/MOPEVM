//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Лаба5.2 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskG
//05.12.2023
#include <stdio.h>
 
int main() {
    int N, M, K;
    unsigned long long TMP;
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.bin", "wb");
 
    fscanf(fin, "%d %d", &N, &M);
    fscanf(fin, "%d", &K);
 
    fwrite(&N, sizeof(int), 1, fout);
    fwrite(&M, sizeof(int), 1, fout);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(fin,"%llu",&TMP);
            int sum = 0;
            for (int k = 0; k < K; k++){
                unsigned long long t = TMP & 0xFF;
                sum = sum + t;
                TMP = TMP>>8;
            }
            sum /=K;
            fwrite(&sum,sizeof(unsigned char),1,fout);
        }
    }
 
    fclose(fin);
    fclose(fout);
 
    return 0;
}
 