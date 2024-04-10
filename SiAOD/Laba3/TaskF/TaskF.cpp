//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба3.1
//КТбо1-6, Кравченко Александр Андреевич
//TaskF
//24.03.2024
#include <iostream>
#include <unordered_map>
using namespace std;

struct User {
    string password;
    bool state;
};

int main() {
    unordered_map<string, User> users;
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string command, username, password;
        cin >> command >> username;

        if (command == "register") {
            cin >> password;
            if (users.count(username)) {
                cout << "fail: user already exists" << endl;
            } else {
                users[username] = {password, false};
                cout << "success: new user added" << endl;
            }

        } 
        else if (command == "login") {
            cin >> password;
            if (!users.count(username)) {
                cout << "fail: no such user" << endl;
            } else if (users[username].password != password) {
                cout << "fail: incorrect password" << endl;
            } else if (users[username].state) {
                cout << "fail: already logged in" << endl;
            } else {
                users[username].state = true;
                cout << "success: user logged in" << endl;
            }
            
        } 
        else if (command == "logout") {
            if (!users.count(username)) {
                cout << "fail: no such user" << endl;
            } else if (!users[username].state) {
                cout << "fail: already logged out" << endl;
            } else {
                users[username].state = false;
                cout << "success: user logged out" << endl;
            }
        }
    }
}
