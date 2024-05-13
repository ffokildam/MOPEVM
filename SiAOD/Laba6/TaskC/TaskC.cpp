// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskC
// 12.05.2024

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int totalB = 0;
    int totalR = 0;
    for (char ch : input) {
        if (ch == 'B') totalB++;
        else if (ch == 'R') totalR++;
    }

    int maxB = 0;
    int countB = 0; 
    int countR = 0; 
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 'B') countB++;
        else if (input[i] == 'R') countR++;
        if (countR == 0) {
            maxB = countB;
        }
    }
    int removedB = totalB - maxB;

    string result(maxB, 'B');
    result.append(string(totalR, 'R'));
    
    cout << result << endl;
    cout << removedB << endl;

    return 0;
}
