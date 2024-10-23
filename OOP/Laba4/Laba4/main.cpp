#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm> 

class Library {
public:
    std::string name; // ��� ������
    std::string title; // ��������
    int publishYear; // ��� �������
    int num; // ���-�� �����������

    Library(std::string n, std::string t, int pY, int nu) : name(n), title(t), publishYear(pY), num(nu) {};
};

// ������� ������ ���� ������� � ���������� ��� ����������
void displayAuthors(const std::vector<Library>& library) {
    std::set<std::string> authors;
    for (const auto& book : library) {
        authors.insert(book.name);
    }

    std::cout << "�������� ������� ��� ��������:" << std::endl;
    for (const auto& author : authors) {
        std::cout << author << std::endl;
    }
}

// ������� ����������� ���� ���� ������, ���������� ����� ����������� ����
void displayBooksByAuthor(const std::vector<Library>& library, const std::string& author, int startYear) {
    std::cout << "�������� � ������ ������ \"" << author << "\" ������� � " << startYear << " ����:" << std::endl;

    // ����� ������ ����� � ���������(��������, ���������� �� ������)
    auto it = std::find_if(library.begin(), library.end(),
        [&author, startYear](const Library& book) {
            return book.name == author && book.publishYear >= startYear;
        });

    bool found = false;
    while (it != library.end()) {
        std::cout << "��������: " << it->title << ", ��� �������: " << it->publishYear
            << ", ���������� �����������: " << it->num << std::endl;
        found = true;

        // ����� ��������� ����� � ���� �� ���������
        it = std::find_if(std::next(it), library.end(),
            [&author, startYear](const Library& book) {
                return book.name == author && book.publishYear >= startYear;
            });
    }

    if (!found) {
        std::cout << "��� ���� ������ \"" << author << "\", ������� � " << startYear << " ����." << std::endl;
    }
}

int main() {
    try {
        setlocale(LC_ALL, "rus");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        std::vector<Library> library;
        std::ifstream inputFile("books.txt");

        if (!inputFile.is_open()) {
            throw 1; // ������� ���������� � ����� 1, ���� ���� �� ��������
        }

        std::string name, title;
        int publishYear, num;
        
        // ���������� ������ � �����
        while (std::getline(inputFile, name)) {
            std::getline(inputFile, title);
            inputFile >> publishYear >> num;
            if (inputFile.fail()) {
                throw 2; // ������� ���������� � ����� 2, ���� ��������� ������ ��� ������ ������
            }
            inputFile.ignore(); 

            library.emplace_back(name, title, publishYear, num);
        }

        inputFile.close();

        // ����� ������� 
        displayAuthors(library);
        
        // ������ ������ ���� �� �������� ��������
        std::cout << std::endl;
        std::cout << "������� ��� ������: ";
        std::string author;
        std::getline(std::cin, author);
        std::cout << "������� ��� ������ ������: ";
        int year;
        std::cin >> year;

        if (year < 0) {
            throw 3; // ������� ���������� � ����� 3, ���� ��� ������ �������
        }

        displayBooksByAuthor(library, author, year);
    }

    catch (int errorCode) {
        switch (errorCode) {
        case 1:
            std::cerr << "������: �� ������� ������� ���� books.txt" << std::endl;
            break;
        case 2:
            std::cerr << "������: ��������� ������ ��� ������ ������ �� �����" << std::endl;
            break;
        case 3:
            std::cerr << "������: ������ ������������ ���" << std::endl;
            break;
        default:
            std::cerr << "����������� ������" << std::endl;
            break;
        }
        return errorCode;
    }

    return 0;
}
