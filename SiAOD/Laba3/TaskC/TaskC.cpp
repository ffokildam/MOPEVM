//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба2.2
//КТбо1-6, Кравченко Александр Андреевич
//TaskC
//14.03.2024
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> bank;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int type;
        string name;
        cin >> type >> name;
        if (type == 1) {
            int amount;
            cin >> amount;
            bank[name] += amount;
        } else if (type == 2) {
            if (bank.find(name) != bank.end()) {
                cout << bank[name] << endl;
            } else {
                cout << "ERROR" << endl;
            }
        }
    }
    return 0;
}
