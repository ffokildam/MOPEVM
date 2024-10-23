#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Element {

protected:
	std::string Name;
public:
	Element(std::string _name) : Name(_name) {}

	std::string getName() const {
		return Name;
	}

	virtual bool operate(bool o1, bool o2) = 0;

	virtual ~Element() {}

};

class AND : public Element {
public:
	AND() : Element("AND") {}

	bool operate(bool o1, bool o2) override {
		return o1 && o2;
	}
};

class OR : public Element {
public:
	OR() : Element("OR") {}

	bool operate(bool o1, bool o2) override {
		return o1 || o2;
	}
};

class XOR : public Element {
public:
	XOR() : Element("XOR") {}

	bool operate(bool o1, bool o2) override {
		return o1 != o2;
	}
};


class Scheme {
private:
	Element** register1{};
	Element** register2{};

	int size{};

	Element* createRandomElement() {
		int type = rand() % 3;
		switch (type) {
		case 0: return new AND();
		case 1: return new OR();
		case 2: return new XOR();
		}
	}
public:
	void createScheme(int n) {
		size = n;
		register1 = new Element * [size];
		register2 = new Element * [size / 2];
		std::cout << "Reg1: ";
		for (int i = 0; i < size; i++)
		{
			register1[i] = createRandomElement();
			std::cout << register1[i]->getName() << ' ';
		}
		std::cout << "\nReg2: ";
		for (int i = 0; i < size / 2; i++) {
			register2[i] = createRandomElement();
			std::cout << register2[i]->getName() << ' ';
		}
		std::cout << "\nРегистры 1 и 2 были заполнены случайными элементами как показано выше\n";
	}
	void calcElement(bool input1, bool input2) {
		int tempN{};
		std::cout << "Введите размер первого регистра: ";
		while (true) {
			std::cin >> tempN;
			if ((tempN > 0) && ((tempN & (tempN - 1)) == 0)) {
				createScheme(tempN);
				break;
			}
			else {
				std::cout << "Введенный размер регистра не является степенью 2, попробуйте ещё раз: ";
			}
		}
		for (int i = 0; i < size-1; i+=2) {
			bool output1 = register1[i]->operate(input1, input2);
			bool output2 = register1[i + 1]->operate(input1, input2);

			bool finalOutput = register2[i/2]->operate(output1, output2);

			std::cout << register1[i]->getName() << " выход: " << output1 << '\n';
			std::cout << register1[i+1]->getName() << " выход: " << output2 << '\n';
			std::cout << "Итоговый вывод:\n";
			std::cout << register2[i / 2]->getName() << " выход: " << finalOutput << '\n'<<'\n';
		}
	}

	~Scheme() {
		for (int i = 0; i < size; i++) {
			delete register1[i];
		}
		delete[] register1;

		for (int i = 0; i < size/2; i++) {
			delete register2[i];
		}
		delete[] register2;
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	srand(static_cast<unsigned>(time(0)));

	Scheme scheme{};
	scheme.calcElement(true,false);

	return 0;
}