// ЮФУ, ИКТИБ, МОП ЭВМ
// Структуры и алгоритмы обработки данных
// Лаба 6
// КТбо1-6, Кравченко Александр Андреевич
// TaskB
// 12.05.2024

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

string canFormPalindrome(const string& s) {
    unordered_map<char, int> freq;
    for (char ch : s) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            freq[lower]++;
        }
    }

    int odd = 0;
    string hPalindrome;
    char middleChar = 0;


    for (auto& p : freq) {
        if (p.second % 2 != 0) {
            odd++;
            if (odd > 1) {
                return "NO";
            }
            middleChar = p.first;
        }
        hPalindrome.append(p.second / 2, p.first);
    }


    sort(hPalindrome.begin(), hPalindrome.end(), greater<char>());
    
    string fullPalindrome = hPalindrome;
    if (odd == 1) {
        fullPalindrome += middleChar;
    }
    reverse(hPalindrome.begin(), hPalindrome.end());
    fullPalindrome += hPalindrome;
    
    transform(fullPalindrome.begin(), fullPalindrome.end(), fullPalindrome.begin(), ::toupper);

    return fullPalindrome;
}

int main() {
    string input;
    getline(cin, input);
    string result = canFormPalindrome(input);
    cout << result << endl;
    return 0;
}

