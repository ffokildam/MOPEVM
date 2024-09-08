/**
 * @file TuringClient.h
 * @brief Заголовочный файл для клиентского приложения машины Тьюринга.
 * Хранит в себе прототипы структур и классов, находящихся в библиотеке TuringDLL
 */
#pragma once

#include <map>
#include <vector>
#include <string>

struct Command {
    char writeSymbol; 
    char direction; 
    std::string nextState; 
};
class Tape {
public:
    Tape(const std::string& initialTape);
   
    char read() const;
    
    void write(char symbol);
    
    void moveLeft();
    
    void moveRight();
    
    void print(bool withArrow) const;
    
    void clearTape();

private:
    std::vector<char> tape;
    size_t headPosition;
};
class TuringMachine {
public:
    TuringMachine(const std::map<std::string, std::map<char, Command>>& program, const std::string& initialState, const std::string& initialTape);
    
    virtual void executeStep(int& isEnd);
   
    virtual void run();
    
    virtual void printTape(bool withArrow) const;

private:
    std::map<std::string, std::map<char, Command>> program;
    std::string currentState; 
    Tape tape; 
};