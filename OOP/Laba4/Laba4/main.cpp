#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm> 

class Library {
public:
    std::string name; // ФИО автора
    std::string title; // Название
    int publishYear; // Год издания
    int num; // Кол-во экземпляров

    Library(std::string n, std::string t, int pY, int nu) : name(n), title(t), publishYear(pY), num(nu) {};
};

// Функция вывода всех авторов в библиотеке без повторений
void displayAuthors(const std::vector<Library>& library) {
    std::set<std::string> authors;
    for (const auto& book : library) {
        authors.insert(book.name);
    }

    std::cout << "Перечень авторов без повторов:" << std::endl;
    for (const auto& author : authors) {
        std::cout << author << std::endl;
    }
}

// Функция отображения всех книг автора, выпущенных после конкретного года
void displayBooksByAuthor(const std::vector<Library>& library, const std::string& author, int startYear) {
    std::cout << "Сведения о книгах автора \"" << author << "\" начиная с " << startYear << " года:" << std::endl;

    // Поиск первой книги с условиями(проверка, существует ли вообще)
    auto it = std::find_if(library.begin(), library.end(),
        [&author, startYear](const Library& book) {
            return book.name == author && book.publishYear >= startYear;
        });

    bool found = false;
    while (it != library.end()) {
        std::cout << "Название: " << it->title << ", Год издания: " << it->publishYear
            << ", Количество экземпляров: " << it->num << std::endl;
        found = true;

        // Поиск следующей книги с теми же условиями
        it = std::find_if(std::next(it), library.end(),
            [&author, startYear](const Library& book) {
                return book.name == author && book.publishYear >= startYear;
            });
    }

    if (!found) {
        std::cout << "Нет книг автора \"" << author << "\", начиная с " << startYear << " года." << std::endl;
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
            throw 1; // Бросаем исключение с кодом 1, если файл не открылся
        }

        std::string name, title;
        int publishYear, num;
        
        // Считывание данных с файла
        while (std::getline(inputFile, name)) {
            std::getline(inputFile, title);
            inputFile >> publishYear >> num;
            if (inputFile.fail()) {
                throw 2; // Бросаем исключение с кодом 2, если произошла ошибка при чтении данных
            }
            inputFile.ignore(); 

            library.emplace_back(name, title, publishYear, num);
        }

        inputFile.close();

        // Вывод авторов 
        displayAuthors(library);
        
        // Начало вывода книг по заданным условиям
        std::cout << std::endl;
        std::cout << "Введите ФИО автора: ";
        std::string author;
        std::getline(std::cin, author);
        std::cout << "Введите год начала поиска: ";
        int year;
        std::cin >> year;

        if (year < 0) {
            throw 3; // Бросаем исключение с кодом 3, если год введен неверно
        }

        displayBooksByAuthor(library, author, year);
    }

    catch (int errorCode) {
        switch (errorCode) {
        case 1:
            std::cerr << "Ошибка: не удалось открыть файл books.txt" << std::endl;
            break;
        case 2:
            std::cerr << "Ошибка: произошла ошибка при чтении данных из файла" << std::endl;
            break;
        case 3:
            std::cerr << "Ошибка: введен некорректный год" << std::endl;
            break;
        default:
            std::cerr << "Неизвестная ошибка" << std::endl;
            break;
        }
        return errorCode;
    }

    return 0;
}
