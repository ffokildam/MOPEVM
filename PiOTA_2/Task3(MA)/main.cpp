//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//ДЗ3 - Проектирование и реализация нормального алгоритма Маркова.
//КТбо1-6, Кравченко Александр Андреевич
//25.04.2024
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <regex>

struct SubstTable{
    std::string Sample;     
    std::string Replacement;
    bool endPoint;
};

// Функция проверки входных данных
// Получает на вход строку
// Возвращает значения: 
// 0 - введённая строка соответствует критериям
// 1 - введённая строка не соответствует алфавиту
// 2 - введённая строка пуста
int inputValid(std::string);

// Функция выбора и реализации подстановки для текущего слова и вывода результата шага
// Получает на вход: введённую строку, таблицу подстановок, флаг окончания работы алгоритма
// Проходит по каждому состоянию таблицы сверху вниз. Проверяет введённую строку на наличие образца.
// Если образец найден - меняет его на подстановку, проверяет является ли подстановка конечной, 
// выводит номер подстановки, окрашивает образец в строке, выводит результат подстановки.
// Если не найден - ставит флаг остановки в 1
// В любом случае возвращает строку
std::string Substitution(std::string, const SubstTable* ,bool &);

int main(){
    setlocale(LC_ALL, "Russian");
    
    SubstTable STable[38] = {
        {"+ec","+",0},
        {"+eb","+",0},
        {"+ac","+",0},
        {"+ab","+",0},
        {"ce+","+",0},
        {"be+","+",0},
        {"ca+","+",0},
        {"ba+","+",0},
        {"b+b","bb",0},
        {"c+b","cb",0},
        {"b+c","bc",0},
        {"c+c","cc",0},
        {"b+a","ba",0},
        {"b+e","be",0},
        {"a+c","ac",0},
        {"e+c","ec",0},
        {"c+e","ce",0},
        {"c+a","ca",0},
        {"a+b","ab",0},
        {"e+b","eb",0},
        {"+aa","aa",0},
        {"+ee","ee",0},
        {"+ae","ae",0},
        {"+ea","ea",0},
        {"bab","+",0},
        {"bac","+",0},
        {"beb","+",0},
        {"bec","+",0},
        {"cac","+",0},
        {"cab","+",0},
        {"cec","+",0},
        {"ceb","+",0},
        {"+a+","a",0},
        {"+b+","b",0},
        {"+c+","c",0},
        {"+e+","e",0},
        {"++","",0},
        {"+","",1},
    };
    
    std::string input;
    char cont = -1;

    do{
        bool stop = 0;
        if(cont!=1) 
            std::cout<<"Введите входное слово: ";
        std::getline(std::cin,input);
        std::transform(input.begin(), input.end(), input.begin(),[](unsigned char c){ return std::tolower(c); });
        
        int action = inputValid(input);
        if(!action){
            while(stop!=1){
                input = Substitution(input,STable,stop);
            }
            std::cout<<"Результат: "<<input;
            std::cout << "\nНажмите любую клавишу, чтобы продолжить\nДля выхода нажите клавишу ESC на клавиатуре";
            cont = _getch();
            std::cout << "\n\n";
        }
        else if(action == 1){
            cont = 1;
            std::cout<<"Введённая последовательность не соответствует алфавиту {a,b,c,e}\n\nПопробуйте ввести другую последовательность: ";
        }
        else if(action == 2){
            cont = 1;
            std::cout<<"Введённая последовательность является пустой\n\nПопробуйте ввести другую последовательность: ";
        }
    } while (cont != 27);
    std::cout<<"Спасибо за использование!";
    return 0;
}

int inputValid(std::string input) {
    const std::regex validSymbols("^(a|b|c|e)+$");
    if (input.empty()) return 2;
    if (!regex_match(input, validSymbols)) return 1;
    return 0;
}

std::string Substitution(std::string input, const SubstTable* STable,bool &stop){
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    std::string noSub = input;
    
    for (int i = 0; i < 38; i++)
    {
        size_t replacePos = input.find(STable[i].Sample);
        if(replacePos != std::string::npos){
            stop = STable[i].endPoint;
            input.replace(replacePos, STable[i].Sample.size(), STable[i].Replacement);

            std::cout<<"("<<i+1<<") ";
            for (int j = 0; j < noSub.size(); j++)
            {
                SetConsoleTextAttribute(hConsoleHandle, (j >= replacePos && j < replacePos + STable[i].Sample.size()) ? 4 : 15);
                std::cout << noSub[j];
            }
            SetConsoleTextAttribute(hConsoleHandle, 15);
            std::cout << " -> "<<input<<"\n";
            return input;
        }
    }
    stop = 1;
    return input;
}