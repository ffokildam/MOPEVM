/**
  * @file TuringDLL.cpp
  * @brief Файл реализации для машины Тьюринга.
  */
#include "pch.h"
#include "TuringDLL.h"
#include <iostream>
#include <fstream>

Tape::Tape(const std::string& initialTape) : tape(initialTape.begin(), initialTape.end()), headPosition(0) {
    if (tape.empty()) {
        tape.push_back('_');
    }
}

char Tape::read() const {
    return tape[headPosition];
}

void Tape::write(char symbol) {
    tape[headPosition] = symbol;
}

void Tape::moveLeft() {
    if (headPosition == 0) {
        tape.insert(tape.begin(), '_');
    }
    else {
        --headPosition;
    }
}

void Tape::moveRight() {
    ++headPosition;
    if (headPosition >= tape.size()) {
        tape.push_back('_');
    }
}

void Tape::print(bool withArrow) const {
    for (char symbol : tape) {
        std::cout << symbol;
    }
    std::cout << '\n';
    if (withArrow) {
        for (int i = 0; i < headPosition; i++) {
            std::cout << ' ';
        }
        std::cout << '^' << '\n';
    }
}

void Tape::clearTape() {
    for (int i = 0; i < tape.size(); i++) {
        if (tape[i] == '_') tape[i] = ' ';
    }
}

TuringMachine::TuringMachine(const std::map<std::string, std::map<char, Command>>& program, const std::string& initialState, const std::string& initialTape)
    : program(program), currentState(initialState), tape(initialTape) {}

void TuringMachine::executeStep(int& isEnd) {
    char currentSymbol = tape.read();

    if (!program.count(currentState) && !program.at(currentState).count(currentSymbol)) {
        std::cout << "Ошибка соответсвия в таблице переходов на состоянии " << currentState << " символе " << currentSymbol;
        std::cout << "Проверьте таблицу переходов и перезапустите программу";
        isEnd = 1;
    }
    const Command& command = program.at(currentState).at(currentSymbol);

    if (currentState == "q1") {
        std::cout << "Начальное состояние машины: " << currentState << '\n';
        tape.print(1);
    }
    else {
        std::cout << "Текущее состояние машины: " << currentState << '\n';
        tape.print(1);
    }

    tape.write(command.writeSymbol);

    if (command.direction == '<') {
        tape.moveLeft();
    }
    else if (command.direction == '>') {
        tape.moveRight();
    }

    currentState = command.nextState;
    if (currentState == "q0") isEnd = 1;
}

void TuringMachine::run() {
    int isEnd = 0;
    while (!isEnd) {
        executeStep(isEnd);
    }
    tape.clearTape();
}

void TuringMachine::printTape(bool withArrow) const {
    tape.print(withArrow);
}

std::map<std::string, std::map<char, Command>> loadProgram(const std::string& filename, std::string& inputAlphabet) {
    std::map<std::string, std::map<char, Command>> program;
    std::fstream file(filename, std::ios::in);

    if (!file.is_open()) {
        return program;
    }

    file >> inputAlphabet;
    std::string currentState, nextState;
    char readSymbol, writeSymbol, direction;
    while (file >> currentState >> readSymbol >> writeSymbol >> direction >> nextState) {
        program[currentState][readSymbol] = { writeSymbol, direction, nextState };
    }

    file.close();
    return program;
}

TuringMachine * CreateTuringMachine(const std::map<std::string, std::map<char, Command>>&program, const std::string & initialState, const std::string & initialTape) {
    return new TuringMachine(program, initialState, initialTape);
}

void DestroyTuringMachine(TuringMachine * tm) {
    delete tm;
}