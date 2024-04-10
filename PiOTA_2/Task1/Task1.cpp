//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//ДЗ1 - Проектирование и реализация конечного распознавателя.
//КТбо1-6, Кравченко Александр Андреевич
//22.03.2024

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <regex>
#include <windows.h>
#include <Lmcons.h> 

using namespace std;

// Функция инициализации, обработки и хранения таблицы переходов, принимает введённую строку
// Хранит в себе таблицу переходов, а также принимает введенную пользователем последовательность
// Перед отправкой введеной последовательности на проверку допускающего состояния, использует функцию sequenceValid, 
// и в зависимости от возвращенного этой функцией значения либо продолжает работу над строкой, либо передает в main код ошибки, 
// возвращенный функцией sequenceValid
// Если sequenceValid прошла без ошибок, проверяет строку на допускающее состояние функцией sequenceChecker
// Если вернулось значение 1, то значит последовательность допускающая, иначе возвращает 0
// Структура данных:
// Контейнер “map”, первым элементом которого является “string”, 
// являющийся состоянием автомата. Второй же элемент “map”а – также “map”. 
// Он же в свою очередь состоит из “char” и “string”, где “string” – состояние в которое ведёт состояние, 
// отраженное в первом элементе “map”, а “char” – символ, который относится к этому состоянию.
int DFA(string);

// Функция, проверяющая последовательность на корректность ввода, а также проверяющая, не был ли введен символ выхода
// Возвращает значения:
// 5 - если введен символ выхода
// 2 - если введенная строка пустая
// 3 - если в последовательности используются символы не из алфавита(a,b,c)
// 4 - если длина строки меньше 2(отсутствие пары)
int sequenceValid(string);

// Главная функция проверки последовательности, принимает введённую строку, а также таблицу переходов
// Последовательно идёт по каждому символу последовательности, начиная с состояния q0
// Для каждого символа получает его следующее состояние из таблицы переходов transitionTable и сохраняет его в переменной nextState
// Пройдя по всем символам последовательности проверяет, является ли последнее состояние допускающим(ищёт его в сете допускающих состояний valids)
// Если состояние допускающее - возвращает 1
// Иначе - 0
int sequenceChecker(string, const map<string, map<char, string>>& );

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "Russian");
    int returnCode;
    string input;
    SetConsoleTextAttribute(hConsole, 7);

    TCHAR username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (GetUserName(username, &username_len)) {
        wcout << L"Здравствуйте!, " << username << endl;
    }

    while (true)
    {
        cout << "Введите входное слово или введите '0' для выхода из программы: ";
        cin>>input;

        returnCode = DFA(input);

        switch (returnCode) {
        case 0:
            cout << " - No" << endl;
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Введена не допускающая последовательность" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Попробуйте ввести другую последовательность" << endl;
            break;
        case 1:
            cout << " - Yes" << endl;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "Введена допускающая последовательность" << endl;
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Введена пустая последовательность" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Попробуйте ввести другую последовательность" << endl;
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Последовательность содержит недопустимые символы" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Попробуйте ввести другую последовательность, используя символы a,b,c" << endl;
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Длина строки менее 2, невозможно найти пару" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Попробуйте ввести другую последовательность" << endl;
            break;
        case 5:
            cout << "Спасибо за использование!";
            exit(0);
            break;
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout << endl;
    }
}

int sequenceValid(string input) {
    const regex validSymbols("^(a|b|c)+$");
    if (input == "0") return 5;
    if (input.empty()) return 2;
    if (!regex_match(input, validSymbols)) return 3;
    if (input.length() < 2) return 4;
    return 0;
}

int sequenceChecker(string input, const map<string, map<char, string>>& transitionTable)
{
    string nextState,currentState = "q0";
    set<string> valids = { "q4","q9","q13","q16","q21","q25","q28","q33","q37" };

    for (int i = 0; i < input.size(); ++i) {
        nextState = transitionTable.at(currentState).at(input[i]);
        cout << input[i] << ": " << currentState << " -> " << nextState;
        if (i != input.size() - 1) 
            cout << endl;
        currentState = nextState;
    }

    if (valids.contains(currentState)) return 1;
    else return 0;
}

int DFA(string input)
{
    map<string, map<char, string>> transitionTable =
    {
        {"q0" , { {'a', "q1" }, {'b', "q2"}, {'c', "q3"} } },
        {"q1" , { {'a', "q4" }, {'b', "q8"}, {'c', "q12"} } },
        {"q2" , { {'a', "q20" }, {'b', "q16"}, {'c', "q24"} } },
        {"q3" , { {'a', "q36" }, {'b', "q32"}, {'c', "q28"} } },
        {"q4" , { {'a', "q4" }, {'b', "q5"}, {'c', "q6"} } },
        {"q5" , { {'a', "q7" }, {'b', "q5"}, {'c', "q6"} } },
        {"q6" , { {'a', "q7" }, {'b', "q5"}, {'c', "q6"} } },
        {"q7" , { {'a', "q4" }, {'b', "q5"}, {'c', "q6"} } },
        {"q8" , { {'a', "q9" }, {'b', "q8"}, {'c', "q11"} } },
        {"q9" , { {'a', "q10" }, {'b', "q8"}, {'c', "q11"} } },
        {"q10" , { {'a', "q10" }, {'b', "q8"}, {'c', "q11"} } },
        {"q11" , { {'a', "q10" }, {'b', "q8"}, {'c', "q11"} } },
        {"q12" , { {'a', "q13" }, {'b', "q15"}, {'c', "q12"} } },
        {"q13" , { {'a', "q14" }, {'b', "q15"}, {'c', "q12"} } },
        {"q14" , { {'a', "q14" }, {'b', "q15"}, {'c', "q12"} } },
        {"q15" , { {'a', "q14" }, {'b', "q15"}, {'c', "q12"} } },
        {"q16" , { {'a', "q17" }, {'b', "q16"}, {'c', "q18"} } },
        {"q17" , { {'a', "q17" }, {'b', "q19"}, {'c', "q18"} } },
        {"q18" , { {'a', "q17" }, {'b', "q19"}, {'c', "q18"} } },
        {"q19" , { {'a', "q17" }, {'b', "q16"}, {'c', "q18"} } },
        {"q20" , { {'a', "q20" }, {'b', "q21"}, {'c', "q23"} } },
        {"q21" , { {'a', "q20" }, {'b', "q22"}, {'c', "q23"} } },
        {"q22" , { {'a', "q20" }, {'b', "q22"}, {'c', "q23"} } },
        {"q23" , { {'a', "q20" }, {'b', "q22"}, {'c', "q23"} } },
        {"q24" , { {'a', "q27" }, {'b', "q25"}, {'c', "q24"} } },
        {"q25" , { {'a', "q27" }, {'b', "q26"}, {'c', "q24"} } },
        {"q26" , { {'a', "q27" }, {'b', "q26"}, {'c', "q24"} } },
        {"q27" , { {'a', "q27" }, {'b', "q26"}, {'c', "q24"} } },
        {"q28" , { {'a', "q30" }, {'b', "q29"}, {'c', "q28"} } },
        {"q29" , { {'a', "q30" }, {'b', "q29"}, {'c', "q31"} } },
        {"q30" , { {'a', "q30" }, {'b', "q29"}, {'c', "q31"} } },
        {"q31" , { {'a', "q30" }, {'b', "q29"}, {'c', "q28"} } },
        {"q32" , { {'a', "q35" }, {'b', "q32"}, {'c', "q33"} } },
        {"q33" , { {'a', "q35" }, {'b', "q32"}, {'c', "q34"} } },
        {"q34" , { {'a', "q35" }, {'b', "q32"}, {'c', "q34"} } },
        {"q35" , { {'a', "q35" }, {'b', "q32"}, {'c', "q34"} } },
        {"q36" , { {'a', "q36" }, {'b', "q39"}, {'c', "q37"} } },
        {"q37" , { {'a', "q36" }, {'b', "q39"}, {'c', "q38"} } },
        {"q38" , { {'a', "q36" }, {'b', "q39"}, {'c', "q38"} } },
        {"q39" , { {'a', "q36" }, {'b', "q39"}, {'c', "q38"} } },

    };

    int sqVaR = sequenceValid(input);

    if (sqVaR != 0) return sqVaR;

    if (sequenceChecker(input, transitionTable)) return 1;

    return 0;
}

