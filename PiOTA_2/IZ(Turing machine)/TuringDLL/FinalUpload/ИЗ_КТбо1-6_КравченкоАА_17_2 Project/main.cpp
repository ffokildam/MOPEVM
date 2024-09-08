/**
 * @file main.cpp
 * @brief ������� ���� ����������� ���������� ������ ��������.
 * 
 * ���, �����, ��� ���
 * ���������������� � ������ ������ ����������
 * �������������� ������� - �������������� � ���������� ������ ��������.
 * ����1-6, ��������� ��������� ���������
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
		std::cout << "���������� TuringDLL.dll �� �������.\n";
		std::cout << "��������� ���������� ������������ �����, � ������������� ���������.\n";
		system("pause");
		return 1;
	}
	std::cout << "���������� TuringDLL.dll ������� ���������.\n";

	LoadProgramFunc = (std::map<std::string, std::map<char, Command>>(*)(const std::string&, std::string&))GetProcAddress(hLib, "loadProgram");
	CreateTuringMachineFunc = (TuringMachine * (*)(const std::map<std::string, std::map<char, Command>>&, const std::string&, const std::string&))GetProcAddress(hLib, "CreateTuringMachine");
	DestroyTuringMachineFunc = (void(*)(TuringMachine*))GetProcAddress(hLib, "DestroyTuringMachine");

	if (!LoadProgramFunc || !CreateTuringMachineFunc || !DestroyTuringMachineFunc) {
		std::cout << "������� �� ������� � ����������.\n";
		std::cout << "��������� ����������� TuringDLL.dll � ������������� ���������.\n";
		system("pause");
		return 1;
	}
	std::cout << "������� ���������� 'TuringDLL.dll' ������� �������������.\n";

	std::string inputAlphabet;
	std::string fileName;
	std::string initialTape /*= "_0001#0101_"*/;
	char cont = -1;
	std::cout << "\n������������!\n������� ����� ������� ����� ���������� � ����������� ������ ������������.\n������� Spacebar ����� ������ ��� �������� �����\n";
	cont = _getch();
	if (cont == ' ')
		std::cin >> fileName;
	else fileName = "machine";
	cont = -1;

	std::map<std::string, std::map<char, Command>> program = LoadProgramFunc(fileName + ".turing", inputAlphabet);

	if (program.empty()) {
		std::cout << "��������� ������ � �������� ����� " << fileName << ".turing" << " ���������, ��������� �� �������� ����� � ����� � ��������� ����������������� �����.\n��������, �������� �� .turing ����������� ������ �����\n���������, ���������� �� ����\n";
		std::cout << "��������� ���� � ��������� ��������� �����\n";
		system("pause");
		return 1;
	}
	const std::regex validSymbols("^(" + inputAlphabet + ")+$");
	std::string back(1, inputAlphabet.back());
	const std::regex delimiter(back);
	std::cout << "�������� �������� ����� " << fileName << ".turing\n";
	do {
		std::cout << "������� ������� ������������������: ";
		std::cin >> initialTape;
		if (!std::regex_match(initialTape, validSymbols)) {
			std::cout << "������� ������������������, �� ��������������� ��������(1,0,#).";
		}
		else if (!std::regex_search(initialTape, delimiter)) {
			std::cout << "�� ��������� ���� ������������������ ����������� �������������� ������ #.";
		}
		else {
			initialTape = '_' + initialTape + '_';
			TuringMachine* tm = CreateTuringMachineFunc(program, "q1", initialTape);
			tm->run();
			std::cout << "������ ������ �������� ���������.\n��������� ������: ";
			tm->printTape(0);
		}
		std::cout << "\n������� ����� �������, ����� ����������\n��� ������ ������ ������� ESC �� ����������";
		cont = _getch();
		std::cout << "\n\n";
	} while (cont != 27);
	return 0;
}