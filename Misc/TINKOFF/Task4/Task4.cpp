/*
    Суть задачи - сократить число цифр, например превратить 3 4 5 в 3...5, или 8 9 10 11 12 в 8...12
    Все...
*/

#include <bits/stdc++.h>

using namespace std;

void printP(const vector<int>& books, int start, int end) {
    cout << books[start];

    if (end > start + 1) {
        cout << " ... " << books[end];
    } else if (end == start + 1) {
        cout << " " << books[end];
    }

    cout << " ";
}

int main() {
    int N;
    cin >> N;

    vector<int> books;

    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        if (find(books.begin(), books.end(), number) == books.end()) {
            books.push_back(number);
        }
    }
    sort(books.begin(),books.end());

    int start = 0;
    int end = 0;

    
    while (start < books.size()) {
        while (end + 1 < books.size() && books[end] + 1 == books[end + 1]) {
            if (end - start >= 2) { 
                break;
            }
            ++end;
        }

        printP(books, start, end);

        ++end;
        start = end;
    }

    return 0;
}
