/*
    На ввод подается строка, а также ее длина
    Необходимо посчитать минимальную и максимальную длину участков заключенных между символамами #, а также концом\началом строки
    Пример:
    as#dsa
    2 3
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    int n;
    
    cin >> n;
    cin>>text;
  
    int min_length = n + 1;
    int max_length = 0;

  
    vector<string> lines;
    int pos = 0;
    while ((pos = text.find('#')) != string::npos) {
        lines.push_back(text.substr(0, pos));
        text.erase(0, pos + 1);
    }

    lines.push_back(text);

    for (const auto& line : lines) {
        int length = line.length();
        min_length = min(min_length, length);
        max_length = max(max_length, length);
    }

    cout << min_length <<" "<< max_length;
    return 0;
}