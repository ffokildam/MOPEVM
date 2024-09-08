/**
 * @file main.cpp
 * @brief Главный файл клиентского приложения машины Тьюринга.
 * 
 * ЮФУ, ИКТИБ, МОП ЭВМ
 * Программирование и основы теории алгоритмов
 * Индивидуальное задание - Проектирование и реализация машины Тьюринга.
 * КТбо1-6, Кравченко Александр Андреевич
 * 25.05.2024
 */
#include <iostream>
#include <conio.h>
#include <regex>
#include <Windows.h>
#include "TuringClient.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	HMODULE hLib = LoadLibrary(L"TuringDLL.dll");

	std::map<std::string, std::map<char, Command>>(*LoadProgramFunc)(const std::string&, std::string&);
	TuringMachine* (*CreateTuringMachineFunc)(const std::map<std::string, std::map<char, Command>>&, const std::string&, const std::string&);
	void (*DestroyTuringMachineFunc)(TuringMachine*);

	if (!hLib) {
		std::cout << "Библиотека TuringDLL.dll не найдена.\n";
		std::cout << "Проверьте директорию исполняемого файла, и перезапустите программу.\n";
		system("pause");
		return 1;
	}
	std::cout << "Библиотека TuringDLL.dll успешно загружена.\n";

	LoadProgramFunc = (std::map<std::string, std::map<char, Command>>(*)(const std::string&, std::string&))GetProcAddress(hLib, "loadProgram");
	CreateTuringMachineFunc = (TuringMachine * (*)(const std::map<std::string, std::map<char, Command>>&, const std::string&, const std::string&))GetProcAddress(hLib, "CreateTuringMachine");
	DestroyTuringMachineFunc = (void(*)(TuringMachine*))GetProcAddress(hLib, "DestroyTuringMachine");

	if (!LoadProgramFunc || !CreateTuringMachineFunc || !DestroyTuringMachineFunc) {
		std::cout << "Функции не найдены в библиотеке.\n";
		std::cout << "Проверьте целостность TuringDLL.dll и перезапустите программу.\n";
		system("pause");
		return 1;
	}
	std::cout << "Функции библиотеки 'TuringDLL.dll' успешно импортированы.\n";

	std::string inputAlphabet;
	std::string fileName;
	std::string initialTape /*= "_0001#0101_"*/;
	char cont = -1;
	std::cout << "\nЗдравствуйте!\nНажмите любую клавишу чтобы продолжить с стандартным файлом конфигурации.\nНажмите Spacebar чтобы ввести своё название файла\n";
	cont = _getch();
	if (cont == ' ')
		std::cin >> fileName;
	else fileName = "machine";
	cont = -1;

	std::map<std::string, std::map<char, Command>> program = LoadProgramFunc(fileName + ".turing", inputAlphabet);

	if (program.empty()) {
		std::cout << "Произошла ошибка в открытии файла " << fileName << ".turing" << " проверьте, совпадает ли название файла в папке с названием конфигурационного файла.\nПроверье, является ли .turing расширением вашего файла\nПроверьте, существует ли файл\n";
		std::cout << "Проверьте файл и запустите программу снова\n";
		system("pause");
		return 1;
	}
	const std::regex validSymbols("^(" + inputAlphabet + ")+$");
	std::string back(1, inputAlphabet.back());
	const std::regex delimiter(back);
	std::cout << "Успешное открытие файла " << fileName << ".turing\n";
	do {
		std::cout << "Введите входную последовательность: ";
		std::cin >> initialTape;
		if (!std::regex_match(initialTape, validSymbols)) {
			std::cout << "Введена последовательность, не соответствующая алфавиту(1,0,#).";
		}
		else if (!std::regex_search(initialTape, delimiter)) {
			std::cout << "Во введенной вами последовательности отстутсвует разделительный символ #.";
		}
		else {
			initialTape = '_' + initialTape + '_';
			TuringMachine* tm = CreateTuringMachineFunc(program, "q1", initialTape);
			tm->run();
			std::cout << "Работа машины Тьюринга завершена.\nРезультат работы: ";
			tm->printTape(0);
		}
		std::cout << "\nНажмите любую клавишу, чтобы продолжить\nДля выхода нажите клавишу ESC на клавиатуре";
		cont = _getch();
		std::cout << "\n\n";
	} while (cont != 27);
	return 0;
}