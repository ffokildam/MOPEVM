#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>

using namespace std;

#define MAXSIZE 50
#define MAXLINE 500
#define MAXLINES 10

class Stack {
  public:
      void push(const char n) {
          last++;
          arr[last] = n;
      }
      void pop() {
          last--;
      }
      char& top() {
          return arr[last];
      }
      bool empty() const {
          return (last == -1);
      }

  private:
    char arr[MAXSIZE];
    int last = -1;
};


void RPNtoStack(char c, Stack& stack, std::string& output) {
    map<char, int> pr = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^',3} };
    if (stack.empty()) stack.push(c);
    else {
        if (c == ')') {
            while (stack.top() != '(') {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.pop();
        }
        else if (c == '(') stack.push(c);
        else {
            while (!stack.empty() && pr[stack.top()] >= pr[c]) {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.push(c);
        }
    }
}

void StackToStr(Stack& stack, string& output) {
    while (!stack.empty()) {    
        output.push_back(stack.top());
        output.push_back(' ');
        stack.pop();
    }
}

void PrintOutput(string out) {
    ofstream file("output.txt", ios::app);

    if (file.is_open()) {
        file << out << '\n';
        file.close();
    }
    else throw "Failed to open file\n";
}

void RPN(string chr) {
    Stack stack;
    string output;
    set<char> valids = {'+','-','*','/','(',')','^'};

    int sizeN = size(chr);
    
    for (int i = 0; i < size(chr); i++)
    {
        if (chr[i] != ' ') {
            if (valids.contains(chr[i])) RPNtoStack(chr[i], stack, output);
            else if (static_cast<int>(chr[i]) <= 57 && static_cast<int>(chr[i]) >= 48) {
                output.push_back(chr[i]);
                if (i < size(chr) - 1) {
                    while (static_cast<int>(chr[i + 1]) <= 57 && static_cast<int>(chr[i + 1]) >= 48) {
                        output.push_back(chr[i + 1]);
                        i++;
                    }
                }
                output.push_back(' ');
            }
            else throw "Wrong input\n";
        }
    }
    StackToStr(stack, output);
    PrintOutput(output);
}

void ReadFile() {
    ifstream file("input.txt");
    string str;

    if (file.is_open()) {
        while (getline(file, str)) RPN(str);
        file.close();
    }
    else throw "Failed to open file\n";
}

int main(){
    setlocale(LC_ALL, "RU");
    ReadFile();   
}
