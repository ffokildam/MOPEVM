#include <iostream>
#include <string>

struct Data {
    std::string title;
    std::string author;
    std::string isbn;
    std::string genre;
    std::string publisher;

    Data(std::string _title, std::string _author, std::string _isbn, std::string _genre, std::string _publisher)
        : title(_title), author(_author), isbn(_isbn), genre(_genre), publisher(_publisher) {};

    bool operator==(const Data& other) const {
        return title == other.title && author == other.author && isbn == other.isbn && genre == other.genre && publisher == other.publisher;
    }

    void print() const {
        std::cout << title << "\t" << author << "\t" << isbn << "\t" << genre << "\t" << publisher << "\n";
    }
};

struct Node {
    Data data;
    Node* prev;
    Node* next;

    Node(Data _data) : data(_data), prev(nullptr), next(nullptr) {};
    Node(Data _data, Node* _prev, Node* _next) : data(_data), prev(_prev), next(_next) {};
};

class List {
private:
    Node* first;
    Node* last;

public:
    List() : first(nullptr), last(nullptr) {}

    bool empty() const {
        return first == nullptr;
    }

    int len() const {
        int index = 0;
        Node* curr = first;
        while (curr != nullptr) {
            ++index;
            curr = curr->next;
        }
        return index;
    }

    int middle() const {
        int _len = len();
        return (_len / 2) + 1;
    }

    void push_back(Data _data) {
        Node* p = new Node(_data, last, nullptr);
        if (empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void push_front(Data _data) {
        Node* p = new Node(_data, nullptr, first);
        if (empty()) {
            first = p;
            last = p;
            return;
        }
        first->prev = p;
        first = p;
    }

    void push_index(int _index, Data _data) {
        Node* p = new Node(_data);
        if (empty()) {
            first = p;
            last = p;
            return;
        }
        if (_index == 1) {
            push_front(_data);
            return;
        } else if (_index == len() + 1) {
            push_back(_data);
            return;
        }
        Node* curr = first;
        for (int i = 1; i < _index - 1; ++i) {
            curr = curr->next;
        }
        p->next = curr->next;
        p->prev = curr;
        curr->next->prev = p;
        curr->next = p;
    }

    void pop_back() {
        if (empty()) return;
        if (last->prev == nullptr) {
            delete last;
            first = nullptr;
            last = nullptr;
            return;
        }
        Node* del_node = last;
        last->prev->next = nullptr;
        last = last->prev;
        delete del_node;
    }

    void pop_front() {
        if (empty()) return;
        if (first->next == nullptr) {
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        Node* del_node = first;
        first->next->prev = nullptr;
        first = first->next;
        delete del_node;
    }

    void pop_index(int _index) {
        if (empty()) return;
        if (_index == 1) {
            pop_front();
            return;
        } else if (_index == len()) {
            pop_back();
            return;
        }
        Node* curr = first;
        for (int i = 1; i < _index; ++i) {
            curr = curr->next;
        }
        Node* del_node = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete del_node;
    }

    void print() const {
        if (empty()) {
            std::cout << "Список пуст!";
            return;
        }
        Node* curr = first;
        while (curr != nullptr) {
            curr->data.print();
            curr = curr->next;
        }
    }

    int search(const Data& _data) const {
        Node* curr = first;
        int index = 1;
        while (curr != nullptr) {
            if (curr->data == _data) {return index;
            }
            curr = curr->next;
            ++index;
        }
        return -1; 
    }

  
    ~List() {
        Node* curr = first;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
int main() {
    List book_list;


    book_list.push_back(Data("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "Fiction", "Scribner"));
    book_list.push_back(Data("1984", "George Orwell", "9780451524935", "Dystopian", "Signet Classics"));
    book_list.push_front(Data("To Kill a Mockingbird", "Harper Lee", "9780061120084", "Fiction", "Harper Perennial Modern Classics"));


    std::cout << "Initial list:\n";
    book_list.print();

  
    book_list.push_index(2, Data("Moby Dick", "Herman Melville", "9781503280786", "Fiction", "CreateSpace Independent Publishing Platform"));

   
    std::cout << "\nList after insertion at index 2:\n";
    book_list.print();

  
    Data search_data("1984", "George Orwell", "9780451524935", "Dystopian", "Signet Classics");
    int index = book_list.search(search_data);
    std::cout << "\nIndex of the searched book: " << index << "\n";


    book_list.pop_back();
    std::cout << "\nList after removing the last book:\n";
    book_list.print();


    book_list.pop_front();
    std::cout << "\nList after removing the first book:\n";
    book_list.print();

 
    book_list.pop_index(2);
    std::cout << "\nList after removing book at index 2:\n";
    book_list.print();

    return 0;
}
